
#ifndef COMMON_WIN32_COMPUTERSYSTEM_H
#define COMMON_WIN32_COMPUTERSYSTEM_H

#include <common/util.h>
#include <drivers/hyperv/wmi/AbstractWmiObject.h>

namespace Drivers {
namespace Hyperv {
namespace Wmi {
namespace Classes {
namespace Common {
typedef struct _Win32_ComputerSystem_Data {
    XML_TYPE_UINT16 AdminPasswordStatus;
    XML_TYPE_BOOL AutomaticManagedPagefile;
    XML_TYPE_BOOL AutomaticResetBootOption;
    XML_TYPE_BOOL AutomaticResetCapability;
    XML_TYPE_UINT16 BootOptionOnLimit;
    XML_TYPE_UINT16 BootOptionOnWatchDog;
    XML_TYPE_BOOL BootROMSupported;
    XML_TYPE_STR BootupState;
    XML_TYPE_STR Caption;
    XML_TYPE_UINT16 ChassisBootupState;
    XML_TYPE_STR CreationClassName;
    XML_TYPE_INT16 CurrentTimeZone;
    XML_TYPE_BOOL DaylightInEffect;
    XML_TYPE_STR Description;
    XML_TYPE_STR DNSHostName;
    XML_TYPE_STR Domain;
    XML_TYPE_UINT16 DomainRole;
    XML_TYPE_BOOL EnableDaylightSavingsTime;
    XML_TYPE_UINT16 FrontPanelResetStatus;
    XML_TYPE_BOOL InfraredSupported;
    XML_TYPE_STR InstallDate;
    XML_TYPE_UINT16 KeyboardPasswordStatus;
    XML_TYPE_STR LastLoadInfo;
    XML_TYPE_STR Manufacturer;
    XML_TYPE_STR Model;
    XML_TYPE_STR Name;
    XML_TYPE_STR NameFormat;
    XML_TYPE_BOOL NetworkServerModeEnabled;
    XML_TYPE_UINT32 NumberOfLogicalProcessors;
    XML_TYPE_UINT32 NumberOfProcessors;
    XML_TYPE_DYN_ARRAY OEMLogoBitmap;
    XML_TYPE_DYN_ARRAY OEMStringArray;
    XML_TYPE_BOOL PartOfDomain;
    XML_TYPE_INT64 PauseAfterReset;
    XML_TYPE_UINT16 PCSystemType;
    XML_TYPE_DYN_ARRAY PowerManagementCapabilities;
    XML_TYPE_BOOL PowerManagementSupported;
    XML_TYPE_UINT16 PowerOnPasswordStatus;
    XML_TYPE_UINT16 PowerState;
    XML_TYPE_UINT16 PowerSupplyState;
    XML_TYPE_STR PrimaryOwnerContact;
    XML_TYPE_STR PrimaryOwnerName;
    XML_TYPE_UINT16 ResetCapability;
    XML_TYPE_INT16 ResetCount;
    XML_TYPE_INT16 ResetLimit;
    XML_TYPE_DYN_ARRAY Roles;
    XML_TYPE_STR Status;
    XML_TYPE_DYN_ARRAY SupportContactDescription;
    XML_TYPE_UINT16 SystemStartupDelay;
    XML_TYPE_DYN_ARRAY SystemStartupOptions;
    XML_TYPE_UINT8 SystemStartupSetting;
    XML_TYPE_STR SystemType;
    XML_TYPE_UINT16 ThermalState;
    XML_TYPE_UINT64 TotalPhysicalMemory;
    XML_TYPE_STR UserName;
    XML_TYPE_UINT16 WakeUpType;
    XML_TYPE_STR Workgroup;

} Win32_ComputerSystem_Data;
SER_DECLARE_TYPE(Win32_ComputerSystem_Data);
typedef struct _Win32_ComputerSystem {
    XmlSerializerInfo *serializerInfo;
    Win32_ComputerSystem_Data *data;
} Win32_ComputerSystem;

#define WIN32_COMPUTERSYSTEM_RESOURCE_URI \
    "http://schemas.microsoft.com/wbem/wsman/1/wmi/root/cimv2/Win32_ComputerSystem"

#define WIN32_COMPUTERSYSTEM_CLASSNAME \
    "Win32_ComputerSystem"

#define WIN32_COMPUTERSYSTEM_WQL_SELECT \
    "select * from Win32_ComputerSystem "

class Win32ComputerSystem : public AbstractWmiObject
{
public:
  Win32ComputerSystem();
};
}
}
}
}
}
#endif /* COMMON_WIN32_COMPUTERSYSTEM_H */

