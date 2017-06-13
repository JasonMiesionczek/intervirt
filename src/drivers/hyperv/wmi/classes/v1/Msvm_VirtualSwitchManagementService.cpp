
#include "Msvm_VirtualSwitchManagementService.h"

namespace Drivers {
    namespace Hyperv {
        namespace Wmi {
            namespace Classes {
                namespace V1 {

                    SER_START_ITEMS(Msvm_VirtualSwitchManagementService_Data)
                        SER_NS_STR(V1_MSVM_VIRTUALSWITCHMANAGEMENTSERVICE_RESOURCE_URI, "Caption", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALSWITCHMANAGEMENTSERVICE_RESOURCE_URI, "Description", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALSWITCHMANAGEMENTSERVICE_RESOURCE_URI, "ElementName", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALSWITCHMANAGEMENTSERVICE_RESOURCE_URI, "InstallDate", 1),
                        SER_NS_DYN_ARRAY(V1_MSVM_VIRTUALSWITCHMANAGEMENTSERVICE_RESOURCE_URI, "OperationalStatus", 0, 0, uint16),
                        SER_NS_DYN_ARRAY(V1_MSVM_VIRTUALSWITCHMANAGEMENTSERVICE_RESOURCE_URI, "StatusDescriptions", 0, 0, string),
                        SER_NS_STR(V1_MSVM_VIRTUALSWITCHMANAGEMENTSERVICE_RESOURCE_URI, "Status", 1),
                        SER_NS_UINT16(V1_MSVM_VIRTUALSWITCHMANAGEMENTSERVICE_RESOURCE_URI, "HealthState", 1),
                        SER_NS_UINT16(V1_MSVM_VIRTUALSWITCHMANAGEMENTSERVICE_RESOURCE_URI, "EnabledState", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALSWITCHMANAGEMENTSERVICE_RESOURCE_URI, "OtherEnabledState", 1),
                        SER_NS_UINT16(V1_MSVM_VIRTUALSWITCHMANAGEMENTSERVICE_RESOURCE_URI, "RequestedState", 1),
                        SER_NS_UINT16(V1_MSVM_VIRTUALSWITCHMANAGEMENTSERVICE_RESOURCE_URI, "EnabledDefault", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALSWITCHMANAGEMENTSERVICE_RESOURCE_URI, "TimeOfLastStateChange", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALSWITCHMANAGEMENTSERVICE_RESOURCE_URI, "SystemCreationClassName", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALSWITCHMANAGEMENTSERVICE_RESOURCE_URI, "SystemName", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALSWITCHMANAGEMENTSERVICE_RESOURCE_URI, "CreationClassName", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALSWITCHMANAGEMENTSERVICE_RESOURCE_URI, "Name", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALSWITCHMANAGEMENTSERVICE_RESOURCE_URI, "PrimaryOwnerName", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALSWITCHMANAGEMENTSERVICE_RESOURCE_URI, "PrimaryOwnerContact", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALSWITCHMANAGEMENTSERVICE_RESOURCE_URI, "StartMode", 1),
                        SER_NS_BOOL(V1_MSVM_VIRTUALSWITCHMANAGEMENTSERVICE_RESOURCE_URI, "Started", 1),

                    SER_END_ITEMS(Msvm_VirtualSwitchManagementService_Data);
                    
                    MsvmVirtualSwitchManagementServiceMeta::MsvmVirtualSwitchManagementServiceMeta()
                            :AbstractWmiObject(
                                V1_MSVM_VIRTUALSWITCHMANAGEMENTSERVICE_WQL_SELECT,
                                V1_MSVM_VIRTUALSWITCHMANAGEMENTSERVICE_CLASSNAME,
                                "http://schemas.microsoft.com/wbem/wsman/1/wmi/root/virtualization/*",
                                V1_MSVM_VIRTUALSWITCHMANAGEMENTSERVICE_RESOURCE_URI,
                                Msvm_VirtualSwitchManagementService_Data_TypeInfo
                            ) {}

                }
            }
        }
    }
}
