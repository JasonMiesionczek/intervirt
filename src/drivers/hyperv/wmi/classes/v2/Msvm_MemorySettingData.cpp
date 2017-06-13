
#include "Msvm_MemorySettingData.h"

namespace Drivers {
    namespace Hyperv {
        namespace Wmi {
            namespace Classes {
                namespace V2 {

                    SER_START_ITEMS(Msvm_MemorySettingData_Data)
                        SER_NS_STR(V2_MSVM_MEMORYSETTINGDATA_RESOURCE_URI, "InstanceID", 1),
                        SER_NS_STR(V2_MSVM_MEMORYSETTINGDATA_RESOURCE_URI, "Caption", 1),
                        SER_NS_STR(V2_MSVM_MEMORYSETTINGDATA_RESOURCE_URI, "Description", 1),
                        SER_NS_STR(V2_MSVM_MEMORYSETTINGDATA_RESOURCE_URI, "ElementName", 1),
                        SER_NS_UINT16(V2_MSVM_MEMORYSETTINGDATA_RESOURCE_URI, "ResourceType", 1),
                        SER_NS_STR(V2_MSVM_MEMORYSETTINGDATA_RESOURCE_URI, "OtherResourceType", 1),
                        SER_NS_STR(V2_MSVM_MEMORYSETTINGDATA_RESOURCE_URI, "ResourceSubType", 1),
                        SER_NS_STR(V2_MSVM_MEMORYSETTINGDATA_RESOURCE_URI, "PoolID", 1),
                        SER_NS_UINT16(V2_MSVM_MEMORYSETTINGDATA_RESOURCE_URI, "ConsumerVisibility", 1),
                        SER_NS_DYN_ARRAY(V2_MSVM_MEMORYSETTINGDATA_RESOURCE_URI, "HostResource", 0, 0, string),
                        SER_NS_STR(V2_MSVM_MEMORYSETTINGDATA_RESOURCE_URI, "AllocationUnits", 1),
                        SER_NS_UINT64(V2_MSVM_MEMORYSETTINGDATA_RESOURCE_URI, "VirtualQuantity", 1),
                        SER_NS_UINT64(V2_MSVM_MEMORYSETTINGDATA_RESOURCE_URI, "Reservation", 1),
                        SER_NS_UINT64(V2_MSVM_MEMORYSETTINGDATA_RESOURCE_URI, "Limit", 1),
                        SER_NS_UINT32(V2_MSVM_MEMORYSETTINGDATA_RESOURCE_URI, "Weight", 1),
                        SER_NS_BOOL(V2_MSVM_MEMORYSETTINGDATA_RESOURCE_URI, "AutomaticAllocation", 1),
                        SER_NS_BOOL(V2_MSVM_MEMORYSETTINGDATA_RESOURCE_URI, "AutomaticDeallocation", 1),
                        SER_NS_STR(V2_MSVM_MEMORYSETTINGDATA_RESOURCE_URI, "Parent", 1),
                        SER_NS_DYN_ARRAY(V2_MSVM_MEMORYSETTINGDATA_RESOURCE_URI, "Connection", 0, 0, string),
                        SER_NS_STR(V2_MSVM_MEMORYSETTINGDATA_RESOURCE_URI, "Address", 1),
                        SER_NS_UINT16(V2_MSVM_MEMORYSETTINGDATA_RESOURCE_URI, "MappingBehavior", 1),
                        SER_NS_STR(V2_MSVM_MEMORYSETTINGDATA_RESOURCE_URI, "AddressOnParent", 1),
                        SER_NS_STR(V2_MSVM_MEMORYSETTINGDATA_RESOURCE_URI, "VirtualQuantityUnits", 1),
                        SER_NS_BOOL(V2_MSVM_MEMORYSETTINGDATA_RESOURCE_URI, "DynamicMemoryEnabled", 1),
                        SER_NS_UINT32(V2_MSVM_MEMORYSETTINGDATA_RESOURCE_URI, "TargetMemoryBuffer", 1),
                        SER_NS_BOOL(V2_MSVM_MEMORYSETTINGDATA_RESOURCE_URI, "IsVirtualized", 1),
                        SER_NS_BOOL(V2_MSVM_MEMORYSETTINGDATA_RESOURCE_URI, "SwapFilesInUse", 1),
                        SER_NS_UINT64(V2_MSVM_MEMORYSETTINGDATA_RESOURCE_URI, "MaxMemoryBlocksPerNumaNode", 1),

                    SER_END_ITEMS(Msvm_MemorySettingData_Data);
                    
                    MsvmMemorySettingDataMeta::MsvmMemorySettingDataMeta()
                            :AbstractWmiObject(
                                V2_MSVM_MEMORYSETTINGDATA_WQL_SELECT,
                                V2_MSVM_MEMORYSETTINGDATA_CLASSNAME,
                                "http://schemas.microsoft.com/wbem/wsman/1/wmi/root/virtualization/v2/*",
                                V2_MSVM_MEMORYSETTINGDATA_RESOURCE_URI,
                                Msvm_MemorySettingData_Data_TypeInfo
                            ) {}

                }
            }
        }
    }
}
