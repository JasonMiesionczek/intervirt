
#include "Msvm_ComputerSystem.h"

namespace Drivers {
namespace Hyperv {
namespace Wmi {
namespace Classes {
namespace V2 {


SER_START_ITEMS(Msvm_ComputerSystem_Data)
    SER_NS_STR(MSVM_COMPUTERSYSTEM_RESOURCE_URI, "Caption", 1),
    SER_NS_STR(MSVM_COMPUTERSYSTEM_RESOURCE_URI, "Description", 1),
    SER_NS_STR(MSVM_COMPUTERSYSTEM_RESOURCE_URI, "ElementName", 1),
    SER_NS_STR(MSVM_COMPUTERSYSTEM_RESOURCE_URI, "InstallDate", 1),
    SER_NS_DYN_ARRAY(MSVM_COMPUTERSYSTEM_RESOURCE_URI, "OperationalStatus", 0, 0, uint16),
    SER_NS_DYN_ARRAY(MSVM_COMPUTERSYSTEM_RESOURCE_URI, "StatusDescriptions", 0, 0, string),
    SER_NS_STR(MSVM_COMPUTERSYSTEM_RESOURCE_URI, "Status", 1),
    SER_NS_UINT16(MSVM_COMPUTERSYSTEM_RESOURCE_URI, "HealthState", 1),
    SER_NS_UINT16(MSVM_COMPUTERSYSTEM_RESOURCE_URI, "EnabledState", 1),
    SER_NS_STR(MSVM_COMPUTERSYSTEM_RESOURCE_URI, "OtherEnabledState", 1),
    SER_NS_UINT16(MSVM_COMPUTERSYSTEM_RESOURCE_URI, "RequestedState", 1),
    SER_NS_UINT16(MSVM_COMPUTERSYSTEM_RESOURCE_URI, "EnabledDefault", 1),
    SER_NS_STR(MSVM_COMPUTERSYSTEM_RESOURCE_URI, "TimeOfLastStateChange", 1),
    SER_NS_STR(MSVM_COMPUTERSYSTEM_RESOURCE_URI, "CreationClassName", 1),
    SER_NS_STR(MSVM_COMPUTERSYSTEM_RESOURCE_URI, "Name", 1),
    SER_NS_STR(MSVM_COMPUTERSYSTEM_RESOURCE_URI, "PrimaryOwnerName", 1),
    SER_NS_STR(MSVM_COMPUTERSYSTEM_RESOURCE_URI, "PrimaryOwnerContact", 1),
    SER_NS_DYN_ARRAY(MSVM_COMPUTERSYSTEM_RESOURCE_URI, "Roles", 0, 0, string),
    SER_NS_STR(MSVM_COMPUTERSYSTEM_RESOURCE_URI, "NameFormat", 1),
    SER_NS_DYN_ARRAY(MSVM_COMPUTERSYSTEM_RESOURCE_URI, "OtherIdentifyingInfo", 0, 0, string),
    SER_NS_DYN_ARRAY(MSVM_COMPUTERSYSTEM_RESOURCE_URI, "IdentifyingDescriptions", 0, 0, string),
    SER_NS_DYN_ARRAY(MSVM_COMPUTERSYSTEM_RESOURCE_URI, "Dedicated", 0, 0, uint16),
    SER_NS_DYN_ARRAY(MSVM_COMPUTERSYSTEM_RESOURCE_URI, "OtherDedicatedDescriptions", 0, 0, string),
    SER_NS_UINT16(MSVM_COMPUTERSYSTEM_RESOURCE_URI, "ResetCapability", 1),
    SER_NS_DYN_ARRAY(MSVM_COMPUTERSYSTEM_RESOURCE_URI, "PowerManagementCapabilities", 0, 0, uint16),
    SER_NS_UINT64(MSVM_COMPUTERSYSTEM_RESOURCE_URI, "OnTimeInMilliseconds", 1),
    SER_NS_STR(MSVM_COMPUTERSYSTEM_RESOURCE_URI, "TimeOfLastConfigurationChange", 1),
    SER_NS_UINT32(MSVM_COMPUTERSYSTEM_RESOURCE_URI, "ProcessID", 1),
    SER_NS_DYN_ARRAY(MSVM_COMPUTERSYSTEM_RESOURCE_URI, "AssignedNumaNodeList", 0, 0, uint16),

SER_END_ITEMS(Msvm_ComputerSystem_Data);

MsvmComputerSystem::MsvmComputerSystem()
        :AbstractWmiObject(
            MSVM_COMPUTERSYSTEM_WQL_SELECT,
            MSVM_COMPUTERSYSTEM_CLASSNAME,
            "http://schemas.microsoft.com/wbem/wsman/1/wmi/root/virtualization/v2/*",
            MSVM_COMPUTERSYSTEM_RESOURCE_URI,
            Msvm_ComputerSystem_Data_TypeInfo
        ) {}

}
}
}
}
}
