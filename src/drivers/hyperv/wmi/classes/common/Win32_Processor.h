
#ifndef COMMON_WIN32_PROCESSOR_H
#define COMMON_WIN32_PROCESSOR_H

#include <common/util.h>
#include <drivers/hyperv/wmi/AbstractWmiObject.h>

namespace Drivers {
namespace Hyperv {
namespace Wmi {
namespace Classes {
namespace Common {
typedef struct _Win32_Processor_Data {
    XML_TYPE_UINT16 AddressWidth;
    XML_TYPE_UINT16 Architecture;
    XML_TYPE_UINT16 Availability;
    XML_TYPE_STR Caption;
    XML_TYPE_UINT32 ConfigManagerErrorCode;
    XML_TYPE_BOOL ConfigManagerUserConfig;
    XML_TYPE_UINT16 CpuStatus;
    XML_TYPE_STR CreationClassName;
    XML_TYPE_UINT32 CurrentClockSpeed;
    XML_TYPE_UINT16 CurrentVoltage;
    XML_TYPE_UINT16 DataWidth;
    XML_TYPE_STR Description;
    XML_TYPE_STR DeviceID;
    XML_TYPE_BOOL ErrorCleared;
    XML_TYPE_STR ErrorDescription;
    XML_TYPE_UINT32 ExtClock;
    XML_TYPE_UINT16 Family;
    XML_TYPE_STR InstallDate;
    XML_TYPE_UINT32 L2CacheSize;
    XML_TYPE_UINT32 L2CacheSpeed;
    XML_TYPE_UINT32 L3CacheSize;
    XML_TYPE_UINT32 L3CacheSpeed;
    XML_TYPE_UINT32 LastErrorCode;
    XML_TYPE_UINT16 Level;
    XML_TYPE_UINT16 LoadPercentage;
    XML_TYPE_STR Manufacturer;
    XML_TYPE_UINT32 MaxClockSpeed;
    XML_TYPE_STR Name;
    XML_TYPE_UINT32 NumberOfCores;
    XML_TYPE_UINT32 NumberOfLogicalProcessors;
    XML_TYPE_STR OtherFamilyDescription;
    XML_TYPE_STR PNPDeviceID;
    XML_TYPE_DYN_ARRAY PowerManagementCapabilities;
    XML_TYPE_BOOL PowerManagementSupported;
    XML_TYPE_STR ProcessorId;
    XML_TYPE_UINT16 ProcessorType;
    XML_TYPE_UINT16 Revision;
    XML_TYPE_STR Role;
    XML_TYPE_STR SocketDesignation;
    XML_TYPE_STR Status;
    XML_TYPE_UINT16 StatusInfo;
    XML_TYPE_STR Stepping;
    XML_TYPE_STR SystemCreationClassName;
    XML_TYPE_STR SystemName;
    XML_TYPE_STR UniqueId;
    XML_TYPE_UINT16 UpgradeMethod;
    XML_TYPE_STR Version;
    XML_TYPE_UINT32 VoltageCaps;

} Win32_Processor_Data;
SER_DECLARE_TYPE(Win32_Processor_Data);
typedef struct _Win32_Processor {
    XmlSerializerInfo *serializerInfo;
    Win32_Processor_Data *data;
} Win32_Processor;

#define COMMON_WIN32_PROCESSOR_RESOURCE_URI \
    "http://schemas.microsoft.com/wbem/wsman/1/wmi/root/cimv2/Win32_Processor"

#define COMMON_WIN32_PROCESSOR_CLASSNAME \
    "Win32_Processor"

#define COMMON_WIN32_PROCESSOR_WQL_SELECT \
    "select * from Win32_Processor "

class Win32Processor : public AbstractWmiObject
{
public:
  Win32Processor();
};
}
}
}
}
}
#endif /* COMMON_WIN32_PROCESSOR_H */

