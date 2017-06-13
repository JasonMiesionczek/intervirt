
#include "Win32_Processor.h"

namespace Drivers {
    namespace Hyperv {
        namespace Wmi {
            namespace Classes {
                namespace Common {

                    SER_START_ITEMS(Win32_Processor_Data)
                        SER_NS_UINT16(COMMON_WIN32_PROCESSOR_RESOURCE_URI, "AddressWidth", 1),
                        SER_NS_UINT16(COMMON_WIN32_PROCESSOR_RESOURCE_URI, "Architecture", 1),
                        SER_NS_UINT16(COMMON_WIN32_PROCESSOR_RESOURCE_URI, "Availability", 1),
                        SER_NS_STR(COMMON_WIN32_PROCESSOR_RESOURCE_URI, "Caption", 1),
                        SER_NS_UINT32(COMMON_WIN32_PROCESSOR_RESOURCE_URI, "ConfigManagerErrorCode", 1),
                        SER_NS_BOOL(COMMON_WIN32_PROCESSOR_RESOURCE_URI, "ConfigManagerUserConfig", 1),
                        SER_NS_UINT16(COMMON_WIN32_PROCESSOR_RESOURCE_URI, "CpuStatus", 1),
                        SER_NS_STR(COMMON_WIN32_PROCESSOR_RESOURCE_URI, "CreationClassName", 1),
                        SER_NS_UINT32(COMMON_WIN32_PROCESSOR_RESOURCE_URI, "CurrentClockSpeed", 1),
                        SER_NS_UINT16(COMMON_WIN32_PROCESSOR_RESOURCE_URI, "CurrentVoltage", 1),
                        SER_NS_UINT16(COMMON_WIN32_PROCESSOR_RESOURCE_URI, "DataWidth", 1),
                        SER_NS_STR(COMMON_WIN32_PROCESSOR_RESOURCE_URI, "Description", 1),
                        SER_NS_STR(COMMON_WIN32_PROCESSOR_RESOURCE_URI, "DeviceID", 1),
                        SER_NS_BOOL(COMMON_WIN32_PROCESSOR_RESOURCE_URI, "ErrorCleared", 1),
                        SER_NS_STR(COMMON_WIN32_PROCESSOR_RESOURCE_URI, "ErrorDescription", 1),
                        SER_NS_UINT32(COMMON_WIN32_PROCESSOR_RESOURCE_URI, "ExtClock", 1),
                        SER_NS_UINT16(COMMON_WIN32_PROCESSOR_RESOURCE_URI, "Family", 1),
                        SER_NS_STR(COMMON_WIN32_PROCESSOR_RESOURCE_URI, "InstallDate", 1),
                        SER_NS_UINT32(COMMON_WIN32_PROCESSOR_RESOURCE_URI, "L2CacheSize", 1),
                        SER_NS_UINT32(COMMON_WIN32_PROCESSOR_RESOURCE_URI, "L2CacheSpeed", 1),
                        SER_NS_UINT32(COMMON_WIN32_PROCESSOR_RESOURCE_URI, "L3CacheSize", 1),
                        SER_NS_UINT32(COMMON_WIN32_PROCESSOR_RESOURCE_URI, "L3CacheSpeed", 1),
                        SER_NS_UINT32(COMMON_WIN32_PROCESSOR_RESOURCE_URI, "LastErrorCode", 1),
                        SER_NS_UINT16(COMMON_WIN32_PROCESSOR_RESOURCE_URI, "Level", 1),
                        SER_NS_UINT16(COMMON_WIN32_PROCESSOR_RESOURCE_URI, "LoadPercentage", 1),
                        SER_NS_STR(COMMON_WIN32_PROCESSOR_RESOURCE_URI, "Manufacturer", 1),
                        SER_NS_UINT32(COMMON_WIN32_PROCESSOR_RESOURCE_URI, "MaxClockSpeed", 1),
                        SER_NS_STR(COMMON_WIN32_PROCESSOR_RESOURCE_URI, "Name", 1),
                        SER_NS_UINT32(COMMON_WIN32_PROCESSOR_RESOURCE_URI, "NumberOfCores", 1),
                        SER_NS_UINT32(COMMON_WIN32_PROCESSOR_RESOURCE_URI, "NumberOfLogicalProcessors", 1),
                        SER_NS_STR(COMMON_WIN32_PROCESSOR_RESOURCE_URI, "OtherFamilyDescription", 1),
                        SER_NS_STR(COMMON_WIN32_PROCESSOR_RESOURCE_URI, "PNPDeviceID", 1),
                        SER_NS_DYN_ARRAY(COMMON_WIN32_PROCESSOR_RESOURCE_URI, "PowerManagementCapabilities", 0, 0, uint16),
                        SER_NS_BOOL(COMMON_WIN32_PROCESSOR_RESOURCE_URI, "PowerManagementSupported", 1),
                        SER_NS_STR(COMMON_WIN32_PROCESSOR_RESOURCE_URI, "ProcessorId", 1),
                        SER_NS_UINT16(COMMON_WIN32_PROCESSOR_RESOURCE_URI, "ProcessorType", 1),
                        SER_NS_UINT16(COMMON_WIN32_PROCESSOR_RESOURCE_URI, "Revision", 1),
                        SER_NS_STR(COMMON_WIN32_PROCESSOR_RESOURCE_URI, "Role", 1),
                        SER_NS_STR(COMMON_WIN32_PROCESSOR_RESOURCE_URI, "SocketDesignation", 1),
                        SER_NS_STR(COMMON_WIN32_PROCESSOR_RESOURCE_URI, "Status", 1),
                        SER_NS_UINT16(COMMON_WIN32_PROCESSOR_RESOURCE_URI, "StatusInfo", 1),
                        SER_NS_STR(COMMON_WIN32_PROCESSOR_RESOURCE_URI, "Stepping", 1),
                        SER_NS_STR(COMMON_WIN32_PROCESSOR_RESOURCE_URI, "SystemCreationClassName", 1),
                        SER_NS_STR(COMMON_WIN32_PROCESSOR_RESOURCE_URI, "SystemName", 1),
                        SER_NS_STR(COMMON_WIN32_PROCESSOR_RESOURCE_URI, "UniqueId", 1),
                        SER_NS_UINT16(COMMON_WIN32_PROCESSOR_RESOURCE_URI, "UpgradeMethod", 1),
                        SER_NS_STR(COMMON_WIN32_PROCESSOR_RESOURCE_URI, "Version", 1),
                        SER_NS_UINT32(COMMON_WIN32_PROCESSOR_RESOURCE_URI, "VoltageCaps", 1),

                    SER_END_ITEMS(Win32_Processor_Data);
                    
                    Win32ProcessorMeta::Win32ProcessorMeta()
                            :AbstractWmiObject(
                                COMMON_WIN32_PROCESSOR_WQL_SELECT,
                                COMMON_WIN32_PROCESSOR_CLASSNAME,
                                "http://schemas.microsoft.com/wbem/wsman/1/wmi/root/cimv2/*",
                                COMMON_WIN32_PROCESSOR_RESOURCE_URI,
                                Win32_Processor_Data_TypeInfo
                            ) {}

                }
            }
        }
    }
}
