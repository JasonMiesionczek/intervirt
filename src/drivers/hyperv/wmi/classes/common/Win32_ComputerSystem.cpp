
#include "Win32_ComputerSystem.h"

namespace Drivers {
    namespace Hyperv {
        namespace Wmi {
            namespace Classes {
                namespace Common {

                    SER_START_ITEMS(Win32_ComputerSystem_Data)
                        SER_NS_UINT16(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "AdminPasswordStatus", 1),
                        SER_NS_BOOL(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "AutomaticManagedPagefile", 1),
                        SER_NS_BOOL(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "AutomaticResetBootOption", 1),
                        SER_NS_BOOL(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "AutomaticResetCapability", 1),
                        SER_NS_UINT16(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "BootOptionOnLimit", 1),
                        SER_NS_UINT16(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "BootOptionOnWatchDog", 1),
                        SER_NS_BOOL(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "BootROMSupported", 1),
                        SER_NS_STR(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "BootupState", 1),
                        SER_NS_STR(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "Caption", 1),
                        SER_NS_UINT16(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "ChassisBootupState", 1),
                        SER_NS_STR(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "CreationClassName", 1),
                        SER_NS_INT16(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "CurrentTimeZone", 1),
                        SER_NS_BOOL(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "DaylightInEffect", 1),
                        SER_NS_STR(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "Description", 1),
                        SER_NS_STR(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "DNSHostName", 1),
                        SER_NS_STR(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "Domain", 1),
                        SER_NS_UINT16(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "DomainRole", 1),
                        SER_NS_BOOL(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "EnableDaylightSavingsTime", 1),
                        SER_NS_UINT16(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "FrontPanelResetStatus", 1),
                        SER_NS_BOOL(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "InfraredSupported", 1),
                        SER_NS_STR(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "InstallDate", 1),
                        SER_NS_UINT16(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "KeyboardPasswordStatus", 1),
                        SER_NS_STR(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "LastLoadInfo", 1),
                        SER_NS_STR(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "Manufacturer", 1),
                        SER_NS_STR(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "Model", 1),
                        SER_NS_STR(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "Name", 1),
                        SER_NS_STR(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "NameFormat", 1),
                        SER_NS_BOOL(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "NetworkServerModeEnabled", 1),
                        SER_NS_UINT32(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "NumberOfLogicalProcessors", 1),
                        SER_NS_UINT32(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "NumberOfProcessors", 1),
                        SER_NS_DYN_ARRAY(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "OEMLogoBitmap", 0, 0, uint8),
                        SER_NS_DYN_ARRAY(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "OEMStringArray", 0, 0, string),
                        SER_NS_BOOL(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "PartOfDomain", 1),
                        SER_NS_INT64(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "PauseAfterReset", 1),
                        SER_NS_UINT16(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "PCSystemType", 1),
                        SER_NS_DYN_ARRAY(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "PowerManagementCapabilities", 0, 0, uint16),
                        SER_NS_BOOL(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "PowerManagementSupported", 1),
                        SER_NS_UINT16(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "PowerOnPasswordStatus", 1),
                        SER_NS_UINT16(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "PowerState", 1),
                        SER_NS_UINT16(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "PowerSupplyState", 1),
                        SER_NS_STR(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "PrimaryOwnerContact", 1),
                        SER_NS_STR(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "PrimaryOwnerName", 1),
                        SER_NS_UINT16(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "ResetCapability", 1),
                        SER_NS_INT16(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "ResetCount", 1),
                        SER_NS_INT16(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "ResetLimit", 1),
                        SER_NS_DYN_ARRAY(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "Roles", 0, 0, string),
                        SER_NS_STR(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "Status", 1),
                        SER_NS_DYN_ARRAY(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "SupportContactDescription", 0, 0, string),
                        SER_NS_UINT16(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "SystemStartupDelay", 1),
                        SER_NS_DYN_ARRAY(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "SystemStartupOptions", 0, 0, string),
                        SER_NS_UINT8(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "SystemStartupSetting", 1),
                        SER_NS_STR(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "SystemType", 1),
                        SER_NS_UINT16(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "ThermalState", 1),
                        SER_NS_UINT64(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "TotalPhysicalMemory", 1),
                        SER_NS_STR(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "UserName", 1),
                        SER_NS_UINT16(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "WakeUpType", 1),
                        SER_NS_STR(COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI, "Workgroup", 1),

                    SER_END_ITEMS(Win32_ComputerSystem_Data);
                    
                    Win32ComputerSystemMeta::Win32ComputerSystemMeta()
                            :AbstractWmiObject(
                                COMMON_WIN32_COMPUTERSYSTEM_WQL_SELECT,
                                COMMON_WIN32_COMPUTERSYSTEM_CLASSNAME,
                                "http://schemas.microsoft.com/wbem/wsman/1/wmi/root/cimv2/*",
                                COMMON_WIN32_COMPUTERSYSTEM_RESOURCE_URI,
                                Win32_ComputerSystem_Data_TypeInfo
                            ) {}

                }
            }
        }
    }
}
