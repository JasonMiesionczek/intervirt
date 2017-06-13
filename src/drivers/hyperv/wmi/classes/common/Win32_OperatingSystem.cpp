
#include "Win32_OperatingSystem.h"

namespace Drivers {
    namespace Hyperv {
        namespace Wmi {
            namespace Classes {
                namespace Common {

                    SER_START_ITEMS(Win32_OperatingSystem_Data)
                        SER_NS_STR(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "BootDevice", 1),
                        SER_NS_STR(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "BuildNumber", 1),
                        SER_NS_STR(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "BuildType", 1),
                        SER_NS_STR(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "Caption", 1),
                        SER_NS_STR(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "CodeSet", 1),
                        SER_NS_STR(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "CountryCode", 1),
                        SER_NS_STR(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "CreationClassName", 1),
                        SER_NS_STR(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "CSCreationClassName", 1),
                        SER_NS_STR(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "CSDVersion", 1),
                        SER_NS_STR(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "CSName", 1),
                        SER_NS_INT16(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "CurrentTimeZone", 1),
                        SER_NS_BOOL(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "DataExecutionPrevention_Available", 1),
                        SER_NS_BOOL(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "DataExecutionPrevention_32BitApplications", 1),
                        SER_NS_BOOL(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "DataExecutionPrevention_Drivers", 1),
                        SER_NS_UINT8(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "DataExecutionPrevention_SupportPolicy", 1),
                        SER_NS_BOOL(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "Debug", 1),
                        SER_NS_STR(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "Description", 1),
                        SER_NS_BOOL(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "Distributed", 1),
                        SER_NS_UINT32(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "EncryptionLevel", 1),
                        SER_NS_UINT8(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "ForegroundApplicationBoost", 1),
                        SER_NS_UINT64(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "FreePhysicalMemory", 1),
                        SER_NS_UINT64(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "FreeSpaceInPagingFiles", 1),
                        SER_NS_UINT64(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "FreeVirtualMemory", 1),
                        SER_NS_STR(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "InstallDate", 1),
                        SER_NS_UINT32(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "LargeSystemCache", 1),
                        SER_NS_STR(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "LastBootUpTime", 1),
                        SER_NS_STR(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "LocalDateTime", 1),
                        SER_NS_STR(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "Locale", 1),
                        SER_NS_STR(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "Manufacturer", 1),
                        SER_NS_UINT32(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "MaxNumberOfProcesses", 1),
                        SER_NS_UINT64(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "MaxProcessMemorySize", 1),
                        SER_NS_DYN_ARRAY(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "MUILanguages", 0, 0, string),
                        SER_NS_STR(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "Name", 1),
                        SER_NS_UINT32(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "NumberOfLicensedUsers", 1),
                        SER_NS_UINT32(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "NumberOfProcesses", 1),
                        SER_NS_UINT32(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "NumberOfUsers", 1),
                        SER_NS_UINT32(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "OperatingSystemSKU", 1),
                        SER_NS_STR(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "Organization", 1),
                        SER_NS_STR(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "OSArchitecture", 1),
                        SER_NS_UINT32(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "OSLanguage", 1),
                        SER_NS_UINT32(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "OSProductSuite", 1),
                        SER_NS_UINT16(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "OSType", 1),
                        SER_NS_STR(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "OtherTypeDescription", 1),
                        SER_NS_BOOL(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "PAEEnabled", 1),
                        SER_NS_STR(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "PlusProductID", 1),
                        SER_NS_STR(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "PlusVersionNumber", 1),
                        SER_NS_BOOL(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "Primary", 1),
                        SER_NS_UINT32(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "ProductType", 1),
                        SER_NS_STR(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "RegisteredUser", 1),
                        SER_NS_STR(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "SerialNumber", 1),
                        SER_NS_UINT16(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "ServicePackMajorVersion", 1),
                        SER_NS_UINT16(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "ServicePackMinorVersion", 1),
                        SER_NS_UINT64(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "SizeStoredInPagingFiles", 1),
                        SER_NS_STR(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "Status", 1),
                        SER_NS_UINT32(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "SuiteMask", 1),
                        SER_NS_STR(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "SystemDevice", 1),
                        SER_NS_STR(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "SystemDirectory", 1),
                        SER_NS_STR(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "SystemDrive", 1),
                        SER_NS_UINT64(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "TotalSwapSpaceSize", 1),
                        SER_NS_UINT64(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "TotalVirtualMemorySize", 1),
                        SER_NS_UINT64(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "TotalVisibleMemorySize", 1),
                        SER_NS_STR(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "Version", 1),
                        SER_NS_STR(COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI, "WindowsDirectory", 1),

                    SER_END_ITEMS(Win32_OperatingSystem_Data);
                    
                    Win32OperatingSystemMeta::Win32OperatingSystemMeta()
                            :AbstractWmiObject(
                                COMMON_WIN32_OPERATINGSYSTEM_WQL_SELECT,
                                COMMON_WIN32_OPERATINGSYSTEM_CLASSNAME,
                                "http://schemas.microsoft.com/wbem/wsman/1/wmi/root/cimv2/*",
                                COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI,
                                Win32_OperatingSystem_Data_TypeInfo
                            ) {}

                }
            }
        }
    }
}
