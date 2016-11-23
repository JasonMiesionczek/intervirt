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
    //XML_TYPE_DYN_ARRAY MUILanguages;
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
//typedef struct _Win32_OperatingSystem_Data Win32_OperatingSystem_Data;
//typedef struct _Win32_OperatingSystem Win32_OperatingSystem;

typedef struct _Win32_OperatingSystem {
    XmlSerializerInfo *serializerInfo;
    Win32_OperatingSystem_Data *data;
} Win32_OperatingSystem;

#define WIN32_OPERATINGSYSTEM_RESOURCE_URI \
    "http://schemas.microsoft.com/wbem/wsman/1/wmi/root/cimv2/Win32_OperatingSystem"

#define WIN32_OPERATINGSYSTEM_CLASSNAME \
    "Win32_OperatingSystem"

#define WIN32_OPERATINGSYSTEM_WQL_SELECT \
    "select * from Win32_OperatingSystem "

#define ROOT_CIMV2 \
    "http://schemas.microsoft.com/wbem/wsman/1/wmi/root/cimv2/*"



SER_START_ITEMS(Win32_OperatingSystem_Data)
    SER_NS_STR(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "BootDevice", 1),
    SER_NS_STR(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "BuildNumber", 1),
    SER_NS_STR(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "BuildType", 1),
    SER_NS_STR(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "Caption", 1),
    SER_NS_STR(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "CodeSet", 1),
    SER_NS_STR(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "CountryCode", 1),
    SER_NS_STR(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "CreationClassName", 1),
    SER_NS_STR(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "CSCreationClassName", 1),
    SER_NS_STR(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "CSDVersion", 1),
    SER_NS_STR(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "CSName", 1),
    SER_NS_INT16(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "CurrentTimeZone", 1),
    SER_NS_BOOL(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "DataExecutionPrevention_Available", 1),
    SER_NS_BOOL(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "DataExecutionPrevention_32BitApplications", 1),
    SER_NS_BOOL(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "DataExecutionPrevention_Drivers", 1),
    SER_NS_UINT8(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "DataExecutionPrevention_SupportPolicy", 1),
    SER_NS_BOOL(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "Debug", 1),
    SER_NS_STR(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "Description", 1),
    SER_NS_BOOL(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "Distributed", 1),
    SER_NS_UINT32(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "EncryptionLevel", 1),
    SER_NS_UINT8(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "ForegroundApplicationBoost", 1),
    SER_NS_UINT64(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "FreePhysicalMemory", 1),
    SER_NS_UINT64(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "FreeSpaceInPagingFiles", 1),
    SER_NS_UINT64(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "FreeVirtualMemory", 1),
    SER_NS_STR(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "InstallDate", 1),
    SER_NS_UINT32(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "LargeSystemCache", 1),
    SER_NS_STR(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "LastBootUpTime", 1),
    SER_NS_STR(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "LocalDateTime", 1),
    SER_NS_STR(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "Locale", 1),
    SER_NS_STR(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "Manufacturer", 1),
    SER_NS_UINT32(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "MaxNumberOfProcesses", 1),
    SER_NS_UINT64(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "MaxProcessMemorySize", 1),
    //SER_NS_DYN_ARRAY(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "MUILanguages", 0, 0, string),
    SER_NS_STR(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "Name", 1),
    SER_NS_UINT32(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "NumberOfLicensedUsers", 1),
    SER_NS_UINT32(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "NumberOfProcesses", 1),
    SER_NS_UINT32(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "NumberOfUsers", 1),
    SER_NS_UINT32(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "OperatingSystemSKU", 1),
    SER_NS_STR(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "Organization", 1),
    SER_NS_STR(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "OSArchitecture", 1),
    SER_NS_UINT32(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "OSLanguage", 1),
    SER_NS_UINT32(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "OSProductSuite", 1),
    SER_NS_UINT16(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "OSType", 1),
    SER_NS_STR(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "OtherTypeDescription", 1),
    SER_NS_BOOL(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "PAEEnabled", 1),
    SER_NS_STR(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "PlusProductID", 1),
    SER_NS_STR(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "PlusVersionNumber", 1),
    SER_NS_BOOL(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "Primary", 1),
    SER_NS_UINT32(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "ProductType", 1),
    SER_NS_STR(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "RegisteredUser", 1),
    SER_NS_STR(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "SerialNumber", 1),
    SER_NS_UINT16(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "ServicePackMajorVersion", 1),
    SER_NS_UINT16(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "ServicePackMinorVersion", 1),
    SER_NS_UINT64(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "SizeStoredInPagingFiles", 1),
    SER_NS_STR(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "Status", 1),
    SER_NS_UINT32(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "SuiteMask", 1),
    SER_NS_STR(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "SystemDevice", 1),
    SER_NS_STR(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "SystemDirectory", 1),
    SER_NS_STR(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "SystemDrive", 1),
    SER_NS_UINT64(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "TotalSwapSpaceSize", 1),
    SER_NS_UINT64(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "TotalVirtualMemorySize", 1),
    SER_NS_UINT64(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "TotalVisibleMemorySize", 1),
    SER_NS_STR(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "Version", 1),
    SER_NS_STR(WIN32_OPERATINGSYSTEM_RESOURCE_URI, "WindowsDirectory", 1),
SER_END_ITEMS(Win32_OperatingSystem_Data);

class Win32OperatingSystem : public AbstractWmiObject
{
public:
    Win32OperatingSystem()
        :AbstractWmiObject(
            WIN32_OPERATINGSYSTEM_WQL_SELECT,
            WIN32_OPERATINGSYSTEM_CLASSNAME,
            ROOT_CIMV2,
            WIN32_OPERATINGSYSTEM_RESOURCE_URI,
            Win32_OperatingSystem_Data_TypeInfo
        ) {}
};

}
}
}
}
}


#endif /* COMMON_WIN32_OPERATINGSYSTEM_H */
