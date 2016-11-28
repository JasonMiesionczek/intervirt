
#include "Msvm_VirtualSystemManagementService.h"

namespace Drivers {
namespace Hyperv {
namespace Wmi {
namespace Classes {
namespace V2 {


SER_START_ITEMS(Msvm_VirtualSystemManagementService_Data)
    SER_NS_STR(MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_RESOURCE_URI, "InstanceID", 1),
    SER_NS_STR(MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_RESOURCE_URI, "Caption", 1),
    SER_NS_STR(MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_RESOURCE_URI, "Description", 1),
    SER_NS_STR(MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_RESOURCE_URI, "ElementName", 1),
    SER_NS_STR(MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_RESOURCE_URI, "InstallDate", 1),
    SER_NS_STR(MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_RESOURCE_URI, "Name", 1),
    SER_NS_DYN_ARRAY(MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_RESOURCE_URI, "OperationalStatus", 0, 0, uint16),
    SER_NS_DYN_ARRAY(MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_RESOURCE_URI, "StatusDescriptions", 0, 0, string),
    SER_NS_STR(MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_RESOURCE_URI, "Status", 1),
    SER_NS_UINT16(MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_RESOURCE_URI, "HealthState", 1),
    SER_NS_UINT16(MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_RESOURCE_URI, "CommunicationStatus", 1),
    SER_NS_UINT16(MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_RESOURCE_URI, "DetailedStatus", 1),
    SER_NS_UINT16(MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_RESOURCE_URI, "OperatingStatus", 1),
    SER_NS_UINT16(MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_RESOURCE_URI, "PrimaryStatus", 1),
    SER_NS_UINT16(MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_RESOURCE_URI, "EnabledState", 1),
    SER_NS_STR(MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_RESOURCE_URI, "OtherEnabledState", 1),
    SER_NS_UINT16(MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_RESOURCE_URI, "RequestedState", 1),
    SER_NS_UINT16(MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_RESOURCE_URI, "EnabledDefault", 1),
    SER_NS_STR(MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_RESOURCE_URI, "TimeOfLastStateChange", 1),
    SER_NS_DYN_ARRAY(MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_RESOURCE_URI, "AvailableRequestedStates", 0, 0, uint16),
    SER_NS_UINT16(MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_RESOURCE_URI, "TransitioningToState", 1),
    SER_NS_STR(MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_RESOURCE_URI, "SystemCreationClassName", 1),
    SER_NS_STR(MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_RESOURCE_URI, "SystemName", 1),
    SER_NS_STR(MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_RESOURCE_URI, "CreationClassName", 1),
    SER_NS_STR(MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_RESOURCE_URI, "PrimaryOwnerName", 1),
    SER_NS_STR(MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_RESOURCE_URI, "PrimaryOwnerContact", 1),
    SER_NS_STR(MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_RESOURCE_URI, "StartMode", 1),
    SER_NS_BOOL(MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_RESOURCE_URI, "Started", 1),

SER_END_ITEMS(Msvm_VirtualSystemManagementService_Data);

MsvmVirtualSystemManagementService::MsvmVirtualSystemManagementService()
        :AbstractWmiObject(
            MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_WQL_SELECT,
            MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_CLASSNAME,
            "",
            MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_RESOURCE_URI,
            Msvm_VirtualSystemManagementService_Data_TypeInfo
        ) {}

}
}
}
}
}
