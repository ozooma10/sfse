#include <cstddef>
#include <cstdint>
#include <type_traits>

#include "sfse/PluginAPI.h"

static_assert(std::is_same_v<PluginHandle, std::uint32_t>);
static_assert(kPluginHandle_Invalid == 0xFFFFFFFF);

static_assert(kInterface_Invalid == 0);
static_assert(kInterface_Messaging == 1);
static_assert(kInterface_Trampoline == 2);
static_assert(kInterface_Menu == 3);
static_assert(kInterface_Task == 4);
static_assert(kInterface_Serialization == 5);
static_assert(kInterface_Max == 6);

static_assert(SFSESerializationInterface::kInterfaceVersion == 1);
static_assert(std::is_standard_layout_v<SFSESerializationInterface>);
static_assert(std::is_trivially_copyable_v<SFSESerializationInterface>);
static_assert(sizeof(SFSESerializationInterface) == 0x68);
static_assert(alignof(SFSESerializationInterface) == alignof(void*));

static_assert(offsetof(SFSESerializationInterface, interfaceVersion) == 0x00);
static_assert(offsetof(SFSESerializationInterface, SetUniqueID) == 0x08);
static_assert(offsetof(SFSESerializationInterface, SetRevertCallback) == 0x10);
static_assert(offsetof(SFSESerializationInterface, SetSaveCallback) == 0x18);
static_assert(offsetof(SFSESerializationInterface, SetLoadCallback) == 0x20);
static_assert(offsetof(SFSESerializationInterface, SetFormDeleteCallback) == 0x28);
static_assert(offsetof(SFSESerializationInterface, WriteRecord) == 0x30);
static_assert(offsetof(SFSESerializationInterface, OpenRecord) == 0x38);
static_assert(offsetof(SFSESerializationInterface, WriteRecordData) == 0x40);
static_assert(offsetof(SFSESerializationInterface, GetNextRecordInfo) == 0x48);
static_assert(offsetof(SFSESerializationInterface, ReadRecordData) == 0x50);
static_assert(offsetof(SFSESerializationInterface, ResolveHandle) == 0x58);
static_assert(offsetof(SFSESerializationInterface, ResolveFormID) == 0x60);

static_assert(std::is_same_v<SFSESerializationInterface::EventCallback, void (*)(const SFSESerializationInterface*)>);
static_assert(std::is_same_v<SFSESerializationInterface::FormDeleteCallback, void (*)(std::uint32_t)>);

static_assert(std::is_same_v<decltype(SFSESerializationInterface::interfaceVersion), std::uint32_t>);
static_assert(std::is_same_v<decltype(SFSESerializationInterface::SetUniqueID), void (*)(PluginHandle, std::uint32_t)>);
static_assert(std::is_same_v<decltype(SFSESerializationInterface::SetRevertCallback), void (*)(PluginHandle, SFSESerializationInterface::EventCallback)>);
static_assert(std::is_same_v<decltype(SFSESerializationInterface::SetSaveCallback), void (*)(PluginHandle, SFSESerializationInterface::EventCallback)>);
static_assert(std::is_same_v<decltype(SFSESerializationInterface::SetLoadCallback), void (*)(PluginHandle, SFSESerializationInterface::EventCallback)>);
static_assert(std::is_same_v<decltype(SFSESerializationInterface::SetFormDeleteCallback), void (*)(PluginHandle, SFSESerializationInterface::FormDeleteCallback)>);
static_assert(std::is_same_v<decltype(SFSESerializationInterface::WriteRecord), bool (*)(std::uint32_t, std::uint32_t, const void*, std::uint32_t)>);
static_assert(std::is_same_v<decltype(SFSESerializationInterface::OpenRecord), bool (*)(std::uint32_t, std::uint32_t)>);
static_assert(std::is_same_v<decltype(SFSESerializationInterface::WriteRecordData), bool (*)(const void*, std::uint32_t)>);
static_assert(std::is_same_v<decltype(SFSESerializationInterface::GetNextRecordInfo), bool (*)(std::uint32_t*, std::uint32_t*, std::uint32_t*)>);
static_assert(std::is_same_v<decltype(SFSESerializationInterface::ReadRecordData), std::uint32_t (*)(void*, std::uint32_t)>);
static_assert(std::is_same_v<decltype(SFSESerializationInterface::ResolveHandle), bool (*)(std::uint64_t, std::uint64_t*)>);
static_assert(std::is_same_v<decltype(SFSESerializationInterface::ResolveFormID), bool (*)(std::uint32_t, std::uint32_t*)>);

int main()
{
	return 0;
}
