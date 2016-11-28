
#include "Msvm_AllocationCapabilities.h"

namespace Drivers {
namespace Hyperv {
namespace Wmi {
namespace Classes {
namespace V1 {

SER_START_ITEMS(Msvm_AllocationCapabilities_Data)
    SER_NS_STR(MSVM_ALLOCATIONCAPABILITIES_RESOURCE_URI, "Caption", 1),
    SER_NS_STR(MSVM_ALLOCATIONCAPABILITIES_RESOURCE_URI, "Description", 1),
    SER_NS_STR(MSVM_ALLOCATIONCAPABILITIES_RESOURCE_URI, "ElementName", 1),
    SER_NS_STR(MSVM_ALLOCATIONCAPABILITIES_RESOURCE_URI, "InstanceID", 1),
    SER_NS_STR(MSVM_ALLOCATIONCAPABILITIES_RESOURCE_URI, "OtherResourceType", 1),
    SER_NS_UINT16(MSVM_ALLOCATIONCAPABILITIES_RESOURCE_URI, "RequestTypesSupported", 1),
    SER_NS_STR(MSVM_ALLOCATIONCAPABILITIES_RESOURCE_URI, "ResourceSubType", 1),
    SER_NS_UINT16(MSVM_ALLOCATIONCAPABILITIES_RESOURCE_URI, "ResourceType", 1),
    SER_NS_UINT16(MSVM_ALLOCATIONCAPABILITIES_RESOURCE_URI, "SharingMode", 1),
    SER_NS_DYN_ARRAY(MSVM_ALLOCATIONCAPABILITIES_RESOURCE_URI, "SupportedAddStates", 0, 0, uint16),
    SER_NS_DYN_ARRAY(MSVM_ALLOCATIONCAPABILITIES_RESOURCE_URI, "SupportedRemoveStates", 0, 0, uint16),

SER_END_ITEMS(Msvm_AllocationCapabilities_Data);

MsvmAllocationCapabilities::MsvmAllocationCapabilities()
        :AbstractWmiObject(
            MSVM_ALLOCATIONCAPABILITIES_WQL_SELECT,
            MSVM_ALLOCATIONCAPABILITIES_CLASSNAME,
            "",
            MSVM_ALLOCATIONCAPABILITIES_RESOURCE_URI,
            Msvm_AllocationCapabilities_Data_TypeInfo
        ) {}

}
}
}
}
}
