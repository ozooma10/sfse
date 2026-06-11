#include "Serialization.h"
#include "GameEvents.h"

#include "sfse_common/Log.h"
#include "sfse_common/Errors.h"
#include "sfse_common/sfse_version.h"
#include "sfse_common/FileStream.h"
#include "sfse/GameSettings.h"
#include "sfse/PluginManager.h"

#include <ShlObj.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <io.h>

namespace Serialization
{
	const char* kSavegamePath = "\\My Games\\" SAVE_FOLDER_NAME "\\";

	struct GlobalDataHeader
	{
		enum
		{
			kSignature =		MACRO_SWAP32('SFSE'),	// endian-swapping so the order matches
			kVersion =			1,
			kVersion_Invalid =	0
		};
		u32	magic;
		u32	formatVersion;
		u32	sfseVersion;
		u32	runtimeVersion;
		u32	numPlugins;
	};

	struct PluginHeader
	{
		u32	signature;
		u32	numChunks;
		u32	length;
	};

	struct ChunkHeader
	{
		u32	type;
		u32	version;
		u32	length;
	};

	std::unordered_map<u32, u32> changedIDs;
	std::unordered_set<u32> deletedIDs;
	std::string s_savePath;


	std::unordered_map<PluginHandle, PluginCallbacks> s_pluginCallbacks;

	struct ChunkOut { u32 type; u32 version; std::vector<u8> data; };
	std::vector<ChunkOut>* s_currentWriteChunks = nullptr;

	struct ChunkIn { u32 type; u32 version; const u8* data; u32 length; };
	std::vector<ChunkIn>*	s_currentReadChunks = nullptr;
	size_t					s_currentReadIdx = static_cast<size_t>(-1);
	u32						s_currentReadByte = 0;

	struct IDRemapDeleteListener :
		public BSTEventSink<TESFormIDRemapEvent>,
		public BSTEventSink<TESFormDeleteEvent>
	{
		IDRemapDeleteListener()
		{
			GetEventSource<TESFormIDRemapEvent>()->RegisterSink(static_cast<BSTEventSink<TESFormIDRemapEvent>*>(this));
			GetEventSource<TESFormDeleteEvent>()->RegisterSink(static_cast<BSTEventSink<TESFormDeleteEvent>*>(this));
		}

		virtual	EventResult	ProcessEvent(const TESFormIDRemapEvent& arEvent, BSTEventSource<TESFormIDRemapEvent>* eventSource)
		{
			changedIDs[arEvent.oldID] = arEvent.newID;
			return EventResult::kContinue;
		};

		virtual	EventResult	ProcessEvent(const TESFormDeleteEvent& arEvent, BSTEventSource<TESFormDeleteEvent>* eventSource)
		{
			deletedIDs.insert(arEvent.formId);

			// notify plugins that registered a form-delete callback
			for (const auto& iter : s_pluginCallbacks)
			{
				if (iter.second.formDelete)
				{
					iter.second.formDelete(static_cast<u64>(arEvent.formId));
				}
			}
			return EventResult::kContinue;
		};
	};

	void RemoveFileExtension(std::string& path)
	{
		size_t lastDot = path.find_last_of('.');
		if (lastDot != std::string::npos) {
			path.erase(lastDot);
		}
	}

	std::string MakeSavePath(std::string name, const char* extension, bool hasExtension)
	{
		if (hasExtension)
		{
			RemoveFileExtension(name);
		}

		char path[MAX_PATH];
		ASSERT(SUCCEEDED(SHGetFolderPath(NULL, CSIDL_MYDOCUMENTS, NULL, SHGFP_TYPE_CURRENT, path)));

		std::string	result = path;
		result += kSavegamePath;
		Setting* localSavePath = (*SettingT<INISettingCollection>::pCollection)->GetSetting("sLocalSavePath:General");
		if (localSavePath && (localSavePath->GetType() == Setting::kType_String))
			result += localSavePath->data.s;
		else
			result += "Saves\\";

		result += "\\";
		result += name;
		if (extension)
			result += extension;
		return result;
	}

	void SetSaveName(const char* name, bool hasExtension)
	{
		if (name)
		{
			_MESSAGE("save name is %s", name);
			s_savePath = MakeSavePath(name, ".sfse", hasExtension);
			_MESSAGE("full save path: %s", s_savePath.c_str());
		}
		else
		{
			_MESSAGE("cleared save path");
			s_savePath.clear();
		}
	}

	void HandleBeginLoad()
	{
		//if the remap listener isn't already registered, register it now.
		static IDRemapDeleteListener listener{};
		changedIDs.clear();
		deletedIDs.clear();
	}

	void HandleEndLoad()
	{
		changedIDs.clear();
		deletedIDs.clear();
	}

	bool ResolveFormId(u32 formId, u32* formIdOut)
	{
		if (auto iter = changedIDs.find(formId); iter != changedIDs.end()) {
			(*formIdOut) = iter->second;
			return true;
		}
		
		if (deletedIDs.find(formId) == deletedIDs.end())
		{
			(*formIdOut) = formId;
			return true;
		}
		else
		{
			return false;
		}
	}

	bool ResolveHandle(u64 handle, u64* handleOut)
	{
		u32 formId = static_cast<u32>(handle & 0x00000000FFFFFFFF);
		if (auto iter = changedIDs.find(formId); iter != changedIDs.end()) {
			(*handleOut) = (handle & 0xFFFFFFFF00000000) | static_cast<u64>(iter->second);
			return true;
		}

		if (deletedIDs.find(formId) == deletedIDs.end())
		{
			(*handleOut) = handle;
			return true;
		}
		else
		{
			return false;
		}
	}

	void HandleRevertGlobalData()
	{
		for (const auto& iter : s_pluginCallbacks)
		{
			if (iter.second.revert)
			{
				iter.second.revert(&g_SFSESerializationInterface);
			}
		}

		changedIDs.clear();
		deletedIDs.clear();
	}

	void HandleSaveGlobalData()
	{
		_MESSAGE("creating co-save");

		if (s_savePath.empty())
		{
			return;
		}

		FileStream::makeDirs(s_savePath.c_str());
		FileStream f;
		if (!f.create(s_savePath.c_str()))
		{
			_ERROR("HandleSaveGlobalData: couldn't create save file (%s)", s_savePath.c_str());
			return;
		}

		GlobalDataHeader header = { GlobalDataHeader::kSignature, GlobalDataHeader::kVersion, PACKED_SFSE_VERSION, RUNTIME_VERSION, 0 };
		f.write(&header, sizeof(header));

		u32 numPlugins = 0;
		for (auto& iter : s_pluginCallbacks)
		{
			PluginCallbacks& cb = iter.second;
			if (!cb.save || !cb.hadUID)
			{
				continue;
			}

			std::vector<ChunkOut> chunks;
			s_currentWriteChunks = &chunks;
			try
			{
				cb.save(&g_SFSESerializationInterface);
			}
			catch (...)
			{
				_ERROR("HandleSaveGlobalData: exception occurred saving %08X at %016I64X data may be corrupt.", cb.uid, f.offset());
			}
			s_currentWriteChunks = nullptr;

			if (chunks.empty())
			{
				continue;
			}

			u32 blockLen = 0;
			for (const auto& c : chunks)
			{
				blockLen += static_cast<u32>(sizeof(ChunkHeader) + c.data.size());
			}

			PluginHeader ph = { cb.uid, static_cast<u32>(chunks.size()), blockLen };
			f.write(&ph, sizeof(ph));
			for (const auto& c : chunks)
			{
				ChunkHeader ch = { c.type, c.version, static_cast<u32>(c.data.size()) };
				f.write(&ch, sizeof(ch));
				if (!c.data.empty())
				{
					f.write(c.data.data(), c.data.size());
				}
			}
			numPlugins++;
		}

		// patch numPlugins
		header.numPlugins = numPlugins;
		f.seek(0);
		f.write(&header, sizeof(header));
		f.close();
	}

	void HandleLoadGlobalData()
	{
		_MESSAGE("loading co-save");

		FileStream f;
		if (s_savePath.empty() || !f.open(s_savePath.c_str()))
		{
			return;
		}

		std::vector<u8> bytes;
		{
			f.seek(0);
			const u64 size = f.length();
			bytes.resize(static_cast<size_t>(size));
			if (size)
				f.read(bytes.data(), size);
			f.close();
		}
		if (bytes.size() < sizeof(GlobalDataHeader))
		{
			return;
		}

		GlobalDataHeader header;
		memcpy(&header, bytes.data(), sizeof(header));
		if (header.magic != GlobalDataHeader::kSignature)
		{
			_ERROR("HandleLoadGame: invalid file signature (found %08X expected %08X)", header.magic, GlobalDataHeader::kSignature);
			return;
		}

		if (header.formatVersion <= GlobalDataHeader::kVersion_Invalid)
		{
			_ERROR("HandleLoadGame: version invalid (%08X)", header.formatVersion);
			return;
		}

		if (header.formatVersion > GlobalDataHeader::kVersion)
		{
			_ERROR("HandleLoadGame: version too new (found %08X current %08X)", header.formatVersion, GlobalDataHeader::kVersion);
			return;
		}

		for (auto& iter : s_pluginCallbacks)
			iter.second.hadData = false;

		size_t cur = sizeof(GlobalDataHeader);
		for (u32 p = 0; p < header.numPlugins; p++)
		{
			if (cur + sizeof(PluginHeader) > bytes.size())
			{
				break;
			}

			PluginHeader ph;
			memcpy(&ph, bytes.data() + cur, sizeof(ph));
			cur += sizeof(PluginHeader);
			const size_t blockStart = cur;
			if (ph.length > bytes.size() - cur)
			{
				_WARNING("HandleLoadGame: plugin with signature %08X not loaded", ph.signature);
				break;
			}
			const size_t blockEnd = cur + ph.length;

			// find a registered plugin with this uid + a load callback
			PluginCallbacks* target = nullptr;
			for (auto& it : s_pluginCallbacks)
			{
				if (it.second.hadUID && it.second.uid == ph.signature && it.second.load)
				{
					target = &it.second;
					break;
				}
			}

			if (target)
			{
				target->hadData = true;

				std::vector<ChunkIn> chunks;
				size_t c = blockStart;
				bool ok = true;
				for (u32 i = 0; i < ph.numChunks; i++)
				{
					if (sizeof(ChunkHeader) > blockEnd - c) { ok = false; break; }
					ChunkHeader ch;
					memcpy(&ch, bytes.data() + c, sizeof(ch));
					c += sizeof(ChunkHeader);
					if (ch.length > blockEnd - c) { ok = false; break; }
					chunks.push_back({ ch.type, ch.version, bytes.data() + c, ch.length });
					c += ch.length;
				}

				if (ok)
				{
					s_currentReadChunks = &chunks;
					s_currentReadIdx = static_cast<size_t>(-1);
					s_currentReadByte = 0;
					try
					{
						target->load(&g_SFSESerializationInterface);
					}
					catch (...)
					{
						_ERROR("HandleLoadGame: exception occurred loading %08X", ph.signature);
					}
					s_currentReadChunks = nullptr;
				}
				else
				{
					_WARNING("HandleLoadGame: plugin with signature %08X not loaded", ph.signature);
				}
			}
			else
			{
				_WARNING("HandleLoadGame: plugin with signature %08X not loaded", ph.signature);
			}

			cur = blockEnd;
		}

		for (auto& iter : s_pluginCallbacks)
		{
			if (!iter.second.hadData && iter.second.load)
			{
				try
				{
					iter.second.load(&g_SFSESerializationInterface);
				}
				catch (...)
				{
					_ERROR("HandleLoadGame: exception occurred loading %08X", iter.second.uid);
				}
			}
		}
	}

	void HandleDeleteSave(std::string saveName)
	{
		// The engine's delete worker passes the bare save name (".sfs" optional);
		// derive both full paths the same way the save path is derived elsewhere.
		std::string savePath = MakeSavePath(saveName, ".sfs", true);
		std::string cosavePath = MakeSavePath(saveName, ".sfse", true);

		// check if old file is gone
		FileStream saveFile;
		if (!saveFile.open(savePath.c_str()))
		{
			_MESSAGE("deleting co-save %s", cosavePath.c_str());
			DeleteFile(cosavePath.c_str());
		}
		else
		{
			_MESSAGE("skipped delete of co-save %s", cosavePath.c_str());
		}
	}

	// ---- plugin-facing API (backs SFSESerializationInterface) ----

	void SetUniqueID(PluginHandle plugin, u32 uid)
	{
		for (const auto& iter : s_pluginCallbacks)
		{
			if (iter.first != plugin && iter.second.hadUID && (iter.second.uid == uid))
			{
				_ERROR("plugin serialization UID collision (uid = %08X, plugins = %d %d)", uid, plugin, iter.first);
			}
		}

		PluginCallbacks& cb = s_pluginCallbacks[plugin];
		ASSERT(!cb.hadUID);

		cb.uid = uid;
		cb.hadUID = true;
	}

	void SetRevertCallback(PluginHandle plugin, SFSESerializationInterface::EventCallback callback)
	{
		s_pluginCallbacks[plugin].revert = callback;
	}

	void SetSaveCallback(PluginHandle plugin, SFSESerializationInterface::EventCallback callback)
	{
		s_pluginCallbacks[plugin].save = callback;
	}

	void SetLoadCallback(PluginHandle plugin, SFSESerializationInterface::EventCallback callback)
	{
		s_pluginCallbacks[plugin].load = callback;
	}

	void SetFormDeleteCallback(PluginHandle plugin, SFSESerializationInterface::FormDeleteCallback callback)
	{
		s_pluginCallbacks[plugin].formDelete = callback;
	}

	bool OpenRecord(u32 type, u32 version)
	{
		if (!s_currentWriteChunks)
			return false;
		s_currentWriteChunks->push_back({ type, version, {} });
		return true;
	}

	bool WriteRecordData(const void* buf, u32 length)
	{
		if (!s_currentWriteChunks || s_currentWriteChunks->empty())
			return false;
		if (buf && length)
		{
			const u8* b = static_cast<const u8*>(buf);
			std::vector<u8>& d = s_currentWriteChunks->back().data;
			d.insert(d.end(), b, b + length);
		}
		return true;
	}

	bool WriteRecord(u32 type, u32 version, const void* buf, u32 length)
	{
		return OpenRecord(type, version) && WriteRecordData(buf, length);
	}

	bool GetNextRecordInfo(u32* type, u32* version, u32* length)
	{
		if (!s_currentReadChunks)
			return false;
		const size_t next = (s_currentReadIdx == static_cast<size_t>(-1)) ? 0 : s_currentReadIdx + 1;
		if (next >= s_currentReadChunks->size())
			return false;
		s_currentReadIdx = next;
		s_currentReadByte = 0;
		const ChunkIn& c = (*s_currentReadChunks)[next];
		if (type)		*type = c.type;
		if (version)	*version = c.version;
		if (length)		*length = c.length;
		return true;
	}

	u32 ReadRecordData(void* buf, u32 length)
	{
		if (!s_currentReadChunks || s_currentReadIdx >= s_currentReadChunks->size())
			return 0;
		const ChunkIn& c = (*s_currentReadChunks)[s_currentReadIdx];
		const u32 take = (length < (c.length - s_currentReadByte)) ? length : (c.length - s_currentReadByte);
		if (buf && take)
			memcpy(buf, c.data + s_currentReadByte, take);
		s_currentReadByte += take;
		return take;
	}
}
