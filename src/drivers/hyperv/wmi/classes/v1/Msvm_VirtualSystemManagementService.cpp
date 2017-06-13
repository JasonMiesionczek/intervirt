
#include "Msvm_VirtualSystemManagementService.h"

namespace Drivers {
    namespace Hyperv {
        namespace Wmi {
            namespace Classes {
                namespace V1 {

                    SER_START_ITEMS(Msvm_VirtualSystemManagementService_Data)
                        SER_NS_STR(V1_MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_RESOURCE_URI, "Caption", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_RESOURCE_URI, "Description", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_RESOURCE_URI, "ElementName", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_RESOURCE_URI, "InstallDate", 1),
                        SER_NS_UINT16(V1_MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_RESOURCE_URI, "OperationalStatus", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_RESOURCE_URI, "StatusDescriptions", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_RESOURCE_URI, "Status", 1),
                        SER_NS_UINT16(V1_MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_RESOURCE_URI, "HealthState", 1),
                        SER_NS_UINT16(V1_MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_RESOURCE_URI, "EnabledState", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_RESOURCE_URI, "OtherEnabledState", 1),
                        SER_NS_UINT16(V1_MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_RESOURCE_URI, "RequestedState", 1),
                        SER_NS_UINT16(V1_MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_RESOURCE_URI, "EnabledDefault", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_RESOURCE_URI, "TimeOfLastStateChange", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_RESOURCE_URI, "SystemCreationClassName", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_RESOURCE_URI, "SystemName", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_RESOURCE_URI, "CreationClassName", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_RESOURCE_URI, "Name", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_RESOURCE_URI, "PrimaryOwnerName", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_RESOURCE_URI, "PrimaryOwnerContact", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_RESOURCE_URI, "StartMode", 1),
                        SER_NS_BOOL(V1_MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_RESOURCE_URI, "Started", 1),

                    SER_END_ITEMS(Msvm_VirtualSystemManagementService_Data);
                    
                    MsvmVirtualSystemManagementServiceMeta::MsvmVirtualSystemManagementServiceMeta()
                            :AbstractWmiObject(
                                V1_MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_WQL_SELECT,
                                V1_MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_CLASSNAME,
                                "http://schemas.microsoft.com/wbem/wsman/1/wmi/root/virtualization/*",
                                V1_MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_RESOURCE_URI,
                                Msvm_VirtualSystemManagementService_Data_TypeInfo
                            ) {}

                }
            }
        }
    }
}
