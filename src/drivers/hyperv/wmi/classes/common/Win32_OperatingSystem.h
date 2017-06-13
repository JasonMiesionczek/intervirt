
#ifndef COMMON_WIN32_OPERATINGSYSTEM_H
#define COMMON_WIN32_OPERATINGSYSTEM_H

#include <common/util.h>
#include <drivers/hyperv/wmi/AbstractWmiObject.h>

namespace Drivers {
    namespace Hyperv {
        namespace Wmi {
            namespace Classes {
                namespace Common {
                    typedef struct _Win32_OperatingSystem_Data {
                        XML_TYPE_STR BootDevice;
                        XML_TYPE_STR BuildNumber;
                        XML_TYPE_STR BuildType;
                        XML_TYPE_STR Caption;
                        XML_TYPE_STR CodeSet;
                        XML_TYPE_STR CountryCode;
                        XML_TYPE_STR CreationClassName;
                        XML_TYPE_STR CSCreationClassName;
                        XML_TYPE_STR CSDVersion;
                        XML_TYPE_STR CSName;
                        XML_TYPE_INT16 CurrentTimeZone;
                        XML_TYPE_BOOL DataExecutionPrevention_Available;
                        XML_TYPE_BOOL DataExecutionPrevention_32BitApplications;
                        XML_TYPE_BOOL DataExecutionPrevention_Drivers;
                        XML_TYPE_UINT8 DataExecutionPrevention_SupportPolicy;
                        XML_TYPE_BOOL Debug;
                        XML_TYPE_STR Description;
                        XML_TYPE_BOOL Distributed;
                        XML_TYPE_UINT32 EncryptionLevel;
                        XML_TYPE_UINT8 ForegroundApplicationBoost;
                        XML_TYPE_UINT64 FreePhysicalMemory;
                        XML_TYPE_UINT64 FreeSpaceInPagingFiles;
                        XML_TYPE_UINT64 FreeVirtualMemory;
                        XML_TYPE_STR InstallDate;
                        XML_TYPE_UINT32 LargeSystemCache;
                        XML_TYPE_STR LastBootUpTime;
                        XML_TYPE_STR LocalDateTime;
                        XML_TYPE_STR Locale;
                        XML_TYPE_STR Manufacturer;
                        XML_TYPE_UINT32 MaxNumberOfProcesses;
                        XML_TYPE_UINT64 MaxProcessMemorySize;
                        XML_TYPE_DYN_ARRAY MUILanguages;
                        XML_TYPE_STR Name;
                        XML_TYPE_UINT32 NumberOfLicensedUsers;
                        XML_TYPE_UINT32 NumberOfProcesses;
                        XML_TYPE_UINT32 NumberOfUsers;
                        XML_TYPE_UINT32 OperatingSystemSKU;
                        XML_TYPE_STR Organization;
                        XML_TYPE_STR OSArchitecture;
                        XML_TYPE_UINT32 OSLanguage;
                        XML_TYPE_UINT32 OSProductSuite;
                        XML_TYPE_UINT16 OSType;
                        XML_TYPE_STR OtherTypeDescription;
                        XML_TYPE_BOOL PAEEnabled;
                        XML_TYPE_STR PlusProductID;
                        XML_TYPE_STR PlusVersionNumber;
                        XML_TYPE_BOOL Primary;
                        XML_TYPE_UINT32 ProductType;
                        XML_TYPE_STR RegisteredUser;
                        XML_TYPE_STR SerialNumber;
                        XML_TYPE_UINT16 ServicePackMajorVersion;
                        XML_TYPE_UINT16 ServicePackMinorVersion;
                        XML_TYPE_UINT64 SizeStoredInPagingFiles;
                        XML_TYPE_STR Status;
                        XML_TYPE_UINT32 SuiteMask;
                        XML_TYPE_STR SystemDevice;
                        XML_TYPE_STR SystemDirectory;
                        XML_TYPE_STR SystemDrive;
                        XML_TYPE_UINT64 TotalSwapSpaceSize;
                        XML_TYPE_UINT64 TotalVirtualMemorySize;
                        XML_TYPE_UINT64 TotalVisibleMemorySize;
                        XML_TYPE_STR Version;
                        XML_TYPE_STR WindowsDirectory;

                    } Win32_OperatingSystem_Data;
                    
                    SER_DECLARE_TYPE(Win32_OperatingSystem_Data);
                    
                    typedef struct _Win32_OperatingSystem {
                        XmlSerializerInfo *serializerInfo;
                        Win32_OperatingSystem_Data *data;
                    } Win32_OperatingSystem;
                    
                    #define COMMON_WIN32_OPERATINGSYSTEM_RESOURCE_URI \
                        "http://schemas.microsoft.com/wbem/wsman/1/wmi/root/cimv2/Win32_OperatingSystem"
                    
                    #define COMMON_WIN32_OPERATINGSYSTEM_CLASSNAME \
                        "Win32_OperatingSystem"
                    
                    #define COMMON_WIN32_OPERATINGSYSTEM_WQL_SELECT \
                        "select * from Win32_OperatingSystem "
                    
                    class Win32OperatingSystemMeta : public AbstractWmiObject
                    {
                    public:
                      Win32OperatingSystemMeta();
                    };
                }
            }
        }
    }
}

#endif /* COMMON_WIN32_OPERATINGSYSTEM_H */

