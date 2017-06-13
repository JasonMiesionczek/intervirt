
#include "Msvm_SyntheticEthernetPortSettingData.h"

namespace Drivers {
    namespace Hyperv {
        namespace Wmi {
            namespace Classes {
                namespace V1 {

                    SER_START_ITEMS(Msvm_SyntheticEthernetPortSettingData_Data)
                        SER_NS_STR(V1_MSVM_SYNTHETICETHERNETPORTSETTINGDATA_RESOURCE_URI, "Caption", 1),
                        SER_NS_STR(V1_MSVM_SYNTHETICETHERNETPORTSETTINGDATA_RESOURCE_URI, "Description", 1),
                        SER_NS_STR(V1_MSVM_SYNTHETICETHERNETPORTSETTINGDATA_RESOURCE_URI, "InstanceID", 1),
                        SER_NS_STR(V1_MSVM_SYNTHETICETHERNETPORTSETTINGDATA_RESOURCE_URI, "ElementName", 1),
                        SER_NS_UINT16(V1_MSVM_SYNTHETICETHERNETPORTSETTINGDATA_RESOURCE_URI, "ResourceType", 1),
                        SER_NS_STR(V1_MSVM_SYNTHETICETHERNETPORTSETTINGDATA_RESOURCE_URI, "OtherResourceType", 1),
                        SER_NS_STR(V1_MSVM_SYNTHETICETHERNETPORTSETTINGDATA_RESOURCE_URI, "ResourceSubType", 1),
                        SER_NS_STR(V1_MSVM_SYNTHETICETHERNETPORTSETTINGDATA_RESOURCE_URI, "PoolID", 1),
                        SER_NS_UINT16(V1_MSVM_SYNTHETICETHERNETPORTSETTINGDATA_RESOURCE_URI, "ConsumerVisibility", 1),
                        SER_NS_DYN_ARRAY(V1_MSVM_SYNTHETICETHERNETPORTSETTINGDATA_RESOURCE_URI, "HostResource", 0, 0, string),
                        SER_NS_STR(V1_MSVM_SYNTHETICETHERNETPORTSETTINGDATA_RESOURCE_URI, "AllocationUnits", 1),
                        SER_NS_UINT64(V1_MSVM_SYNTHETICETHERNETPORTSETTINGDATA_RESOURCE_URI, "VirtualQuantity", 1),
                        SER_NS_UINT64(V1_MSVM_SYNTHETICETHERNETPORTSETTINGDATA_RESOURCE_URI, "Reservation", 1),
                        SER_NS_UINT64(V1_MSVM_SYNTHETICETHERNETPORTSETTINGDATA_RESOURCE_URI, "Limit", 1),
                        SER_NS_UINT32(V1_MSVM_SYNTHETICETHERNETPORTSETTINGDATA_RESOURCE_URI, "Weight", 1),
                        SER_NS_BOOL(V1_MSVM_SYNTHETICETHERNETPORTSETTINGDATA_RESOURCE_URI, "AutomaticAllocation", 1),
                        SER_NS_BOOL(V1_MSVM_SYNTHETICETHERNETPORTSETTINGDATA_RESOURCE_URI, "AutomaticDeallocation", 1),
                        SER_NS_STR(V1_MSVM_SYNTHETICETHERNETPORTSETTINGDATA_RESOURCE_URI, "Parent", 1),
                        SER_NS_DYN_ARRAY(V1_MSVM_SYNTHETICETHERNETPORTSETTINGDATA_RESOURCE_URI, "Connection", 0, 0, string),
                        SER_NS_STR(V1_MSVM_SYNTHETICETHERNETPORTSETTINGDATA_RESOURCE_URI, "Address", 1),
                        SER_NS_UINT16(V1_MSVM_SYNTHETICETHERNETPORTSETTINGDATA_RESOURCE_URI, "MappingBehavior", 1),
                        SER_NS_DYN_ARRAY(V1_MSVM_SYNTHETICETHERNETPORTSETTINGDATA_RESOURCE_URI, "VirtualSystemIdentifiers", 0, 0, string),
                        SER_NS_BOOL(V1_MSVM_SYNTHETICETHERNETPORTSETTINGDATA_RESOURCE_URI, "StaticMacAddress", 1),

                    SER_END_ITEMS(Msvm_SyntheticEthernetPortSettingData_Data);
                    
                    MsvmSyntheticEthernetPortSettingDataMeta::MsvmSyntheticEthernetPortSettingDataMeta()
                            :AbstractWmiObject(
                                V1_MSVM_SYNTHETICETHERNETPORTSETTINGDATA_WQL_SELECT,
                                V1_MSVM_SYNTHETICETHERNETPORTSETTINGDATA_CLASSNAME,
                                "http://schemas.microsoft.com/wbem/wsman/1/wmi/root/virtualization/*",
                                V1_MSVM_SYNTHETICETHERNETPORTSETTINGDATA_RESOURCE_URI,
                                Msvm_SyntheticEthernetPortSettingData_Data_TypeInfo
                            ) {}

                }
            }
        }
    }
}
