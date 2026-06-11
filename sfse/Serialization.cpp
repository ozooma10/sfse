#include "Serialization.h"
#include "GameEvents.h"

#include "sfse_common/Log.h"
#include "sfse_common/Errors.h"
#include "sfse_common/sfse_version.h"
#include "sfse_common/FileStream.h"
#include "sfse/GameSettings.h"
#include "sfse/PluginManager.h"

#include <ShlObj.h>
#include <limits>
#include <mutex>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <io.h>

namespace Serialization
{
#define MACRO_SWAP32(a)			((((a) & 0x000000FF) << 24) | (((a) & 0x0000FF00) << 8) | (((a) & 0x00FF0000) >> 8) | (((a) & 0xFF000000) >> 24))

	const char* kSavegamePath = "\\My Games\\" SAVE_FOLDER_NAME "\\";
	const u64 kMaxCosaveSize = 256ull * 1024ull * 1024ull;

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

	std::mutex s_remapLock;
	std::mutex s_callbackLock;
	std::unordered_map<PluginHandle, PluginCallbacks> s_pluginCallbacks;

	struct ChunkOut { u32 type; u32 version; std::vector<u8> data; };
	std::vector<ChunkOut>* s_currentWriteChunks = nullptr;

	struct ChunkIn { u32 type; u32 version; const u8* data; u32 length; };
	std::vector<ChunkIn>*	s_currentReadChunks = nullptr;
	size_t					s_currentReadIdx = static_cast<size_t>(-1);
	u32						s_currentReadByte = 0;

	struct CallbackSnapshot
	{
		PluginHandle handle;
		PluginCallbacks callbacks;
	};

	std::vector<CallbackSnapshot> GetCallbackSnapshot()
	{
		std::lock_guard<std::mutex> locker(s_callbackLock);

		std::vector<CallbackSnapshot> result;
		result.reserve(s_pluginCallbacks.size());
		for (const auto& iter : s_pluginCallbacks)
		{
			result.push_back({ iter.first, iter.second });
		}
		return result;
	}

	bool SafeCallEventCallback(SFSESerializationInterface::EventCallback callback)
	{
		__try
		{
			callback(&g_SFSESerializationInterface);
			return true;
		}
		__except (EXCEPTION_EXECUTE_HANDLER)
		{
			return false;
		}
	}

	bool SafeCallFormDeleteCallback(SFSESerializationInterface::FormDeleteCallback callback, u32 formId)
	{
		__try
		{
			callback(formId);
			return true;
		}
		__except (EXCEPTION_EXECUTE_HANDLER)
		{
			return false;
		}
	}

	bool WriteFileChecked(FileStream& f, const void* data, u64 length)
	{
		return f.write(data, length) == length;
	}

	bool SeekFileChecked(FileStream& f, u64 offset)
	{
		return f.seek(offset) == offset;
	}

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
			std::lock_guard<std::mutex> locker(s_remapLock);
			changedIDs[arEvent.oldID] = arEvent.newID;
			return EventResult::kContinue;
		};

		virtual	EventResult	ProcessEvent(const TESFormDeleteEvent& arEvent, BSTEventSource<TESFormDeleteEvent>* eventSource)
		{
			{
				std::lock_guard<std::mutex> locker(s_remapLock);
				deletedIDs.insert(arEvent.formId);
			}

			std::vector<CallbackSnapshot> callbacks = GetCallbackSnapshot();
			for (const auto& iter : callbacks)
			{
				if (iter.callbacks.formDelete && !SafeCallFormDeleteCallback(iter.callbacks.formDelete, arEvent.formId))
				{
					_ERROR("FormDelete callback for plugin %u failed", iter.handle);
				}
			}
			return EventResult::kContinue;
		};
	};

	void Initialize()
	{
		static IDRemapDeleteListener listener{};
	}

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
		Initialize();
		std::lock_guard<std::mutex> locker(s_remapLock);
		changedIDs.clear();
		deletedIDs.clear();
	}

	void HandleEndLoad()
	{
		std::lock_guard<std::mutex> locker(s_remapLock);
		changedIDs.clear();
		deletedIDs.clear();
	}

	bool ResolveFormId(u32 formId, u32* formIdOut)
	{
		std::lock_guard<std::mutex> locker(s_remapLock);
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
		std::lock_guard<std::mutex> locker(s_remapLock);
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
		std::vector<CallbackSnapshot> callbacks = GetCallbackSnapshot();
		for (const auto& iter : callbacks)
		{
			if (iter.callbacks.revert && !SafeCallEventCallback(iter.callbacks.revert))
			{
				_ERROR("Revert callback for plugin %u failed", iter.handle);
			}
		}
	}

	void HandleSaveGlobalData()
	{
		_MESSAGE("creating co-save");

		if (s_savePath.empty())
		{
			return;
		}

		std::string tempPath = s_savePath + ".tmp";
		FileStream::makeDirs(tempPath.c_str());
		FileStream f;
		if (!f.create(tempPath.c_str()))
		{
			_ERROR("HandleSaveGlobalData: couldn't create save file (%s)", tempPath.c_str());
			return;
		}

		bool ok = true;
		GlobalDataHeader header = { GlobalDataHeader::kSignature, GlobalDataHeader::kVersion, PACKED_SFSE_VERSION, RUNTIME_VERSION, 0 };
		ok = WriteFileChecked(f, &header, sizeof(header));

		u32 numPlugins = 0;
		std::vector<CallbackSnapshot> callbacks = GetCallbackSnapshot();
		for (auto& iter : callbacks)
		{
			PluginCallbacks& cb = iter.callbacks;
			if (!ok)
			{
				break;
			}

			if (!cb.save)
			{
				continue;
			}

			if (!cb.hadUID)
			{
				_WARNING("HandleSaveGlobalData: plugin %u registered serialization callbacks without a unique ID", iter.handle);
				continue;
			}

			std::vector<ChunkOut> chunks;
			s_currentWriteChunks = &chunks;
			if (!SafeCallEventCallback(cb.save))
			{
				chunks.clear();
				_ERROR("HandleSaveGlobalData: exception occurred while collecting data for %08X; skipping plugin data", cb.uid);
			}
			s_currentWriteChunks = nullptr;

			if (chunks.empty())
			{
				continue;
			}

			u32 blockLen = 0;
			for (const auto& c : chunks)
			{
				if (c.data.size() > (std::numeric_limits<u32>::max)() - sizeof(ChunkHeader) ||
					blockLen > (std::numeric_limits<u32>::max)() - static_cast<u32>(sizeof(ChunkHeader) + c.data.size()))
				{
					_ERROR("HandleSaveGlobalData: plugin %08X wrote too much data", cb.uid);
					ok = false;
					break;
				}
				blockLen += static_cast<u32>(sizeof(ChunkHeader) + c.data.size());
			}

			if (!ok)
			{
				break;
			}

			PluginHeader ph = { cb.uid, static_cast<u32>(chunks.size()), blockLen };
			ok = WriteFileChecked(f, &ph, sizeof(ph));
			for (const auto& c : chunks)
			{
				ChunkHeader ch = { c.type, c.version, static_cast<u32>(c.data.size()) };
				ok = ok && WriteFileChecked(f, &ch, sizeof(ch));
				if (ok && !c.data.empty())
				{
					ok = WriteFileChecked(f, c.data.data(), c.data.size());
				}

				if (!ok)
				{
					break;
				}
			}

			if (ok)
			{
				numPlugins++;
			}
		}

		if (ok)
		{
			header.numPlugins = numPlugins;
			ok = SeekFileChecked(f, 0) && WriteFileChecked(f, &header, sizeof(header));
		}

		f.close();

		if (ok)
		{
			if (!MoveFileEx(tempPath.c_str(), s_savePath.c_str(), MOVEFILE_REPLACE_EXISTING | MOVEFILE_WRITE_THROUGH))
			{
				_ERROR("HandleSaveGlobalData: couldn't replace save file (%s)", s_savePath.c_str());
				DeleteFile(tempPath.c_str());
			}
		}
		else
		{
			_ERROR("HandleSaveGlobalData: write failed; leaving existing co-save untouched (%s)", s_savePath.c_str());
			DeleteFile(tempPath.c_str());
		}
	}

	void HandleLoadGlobalData()
	{
		_MESSAGE("loading co-save");

		FileStream f;
		if (s_savePath.empty() || !f.open(s_savePath.c_str()))
		{
			return;
		}

		const u64 size = f.length();
		if (size < sizeof(GlobalDataHeader))
		{
			return;
		}

		if (size > kMaxCosaveSize)
		{
			_ERROR("HandleLoadGame: co-save too large (%016I64X bytes)", size);
			return;
		}

		GlobalDataHeader header;
		if (f.read(&header, sizeof(header)) != sizeof(header))
		{
			_ERROR("HandleLoadGame: couldn't read co-save header");
			return;
		}

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

		_MESSAGE("HandleLoadGame: co-save sfseVersion=%08X runtimeVersion=%08X", header.sfseVersion, header.runtimeVersion);

		std::vector<u8> bytes;
		{
			f.seek(0);
			bytes.resize(static_cast<size_t>(size));
			if (f.read(bytes.data(), size) != size)
			{
				_ERROR("HandleLoadGame: couldn't read co-save");
				return;
			}
			f.close();
		}

		std::vector<CallbackSnapshot> callbacks = GetCallbackSnapshot();
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
			CallbackSnapshot* target = nullptr;
			for (auto& it : callbacks)
			{
				if (it.callbacks.hadUID && it.callbacks.uid == ph.signature && it.callbacks.load)
				{
					target = &it;
					break;
				}
			}

			if (target)
			{
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
					if (!SafeCallEventCallback(target->callbacks.load))
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
	}

	void HandleDeleteSave(std::string saveName)
	{
		// The engine's delete worker passes the bare save name (".sfs" optional);
		// derive both full paths the same way the save path is derived elsewhere.
		std::string savePath = MakeSavePath(saveName, ".sfs", false);
		std::string cosavePath = MakeSavePath(saveName, ".sfse", false);

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
		std::lock_guard<std::mutex> locker(s_callbackLock);
		PluginCallbacks& cb = s_pluginCallbacks[plugin];
		if (cb.hadUID)
		{
			_WARNING("plugin serialization UID already set (plugin = %d, existing uid = %08X, ignored uid = %08X)", plugin, cb.uid, uid);
			return;
		}

		for (const auto& iter : s_pluginCallbacks)
		{
			if (iter.first != plugin && iter.second.hadUID && (iter.second.uid == uid))
			{
				_ERROR("plugin serialization UID collision (uid = %08X, plugins = %d %d)", uid, plugin, iter.first);
				return;
			}
		}

		cb.uid = uid;
		cb.hadUID = true;
	}

	void SetRevertCallback(PluginHandle plugin, SFSESerializationInterface::EventCallback callback)
	{
		std::lock_guard<std::mutex> locker(s_callbackLock);
		s_pluginCallbacks[plugin].revert = callback;
	}

	void SetSaveCallback(PluginHandle plugin, SFSESerializationInterface::EventCallback callback)
	{
		std::lock_guard<std::mutex> locker(s_callbackLock);
		s_pluginCallbacks[plugin].save = callback;
	}

	void SetLoadCallback(PluginHandle plugin, SFSESerializationInterface::EventCallback callback)
	{
		std::lock_guard<std::mutex> locker(s_callbackLock);
		s_pluginCallbacks[plugin].load = callback;
	}

	void SetFormDeleteCallback(PluginHandle plugin, SFSESerializationInterface::FormDeleteCallback callback)
	{
		Initialize();
		std::lock_guard<std::mutex> locker(s_callbackLock);
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
		if (!buf && length)
			return false;
		if (buf && length)
		{
			const u8* b = static_cast<const u8*>(buf);
			std::vector<u8>& d = s_currentWriteChunks->back().data;
			if (d.size() > (std::numeric_limits<u32>::max)() - length)
				return false;
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
