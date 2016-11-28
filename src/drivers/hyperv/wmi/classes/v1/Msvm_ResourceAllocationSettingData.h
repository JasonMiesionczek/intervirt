
#ifndef V1_MSVM_RESOURCEALLOCATIONSETTINGDATA_H
#define V1_MSVM_RESOURCEALLOCATIONSETTINGDATA_H

#include <common/util.h>
#include <drivers/hyperv/wmi/AbstractWmiObject.h>

namespace Drivers {
namespace Hyperv {
namespace Wmi {
namespace Classes {
namespace V1 {
typedef struct _Msvm_ResourceAllocationSettingData_Data {
    XML_TYPE_STR Caption;
    XML_TYPE_STR Description;
    XML_TYPE_STR InstanceID;
    XML_TYPE_STR ElementName;
    XML_TYPE_UINT16 ResourceType;
    XML_TYPE_STR OtherResourceType;
    XML_TYPE_STR ResourceSubType;
    XML_TYPE_STR PoolID;
    XML_TYPE_UINT16 ConsumerVisibility;
    XML_TYPE_DYN_ARRAY HostResource;
    XML_TYPE_STR AllocationUnits;
    XML_TYPE_UINT64 VirtualQuantity;
    XML_TYPE_UINT64 Reservation;
    XML_TYPE_UINT64 Limit;
    XML_TYPE_UINT32 Weight;
    XML_TYPE_BOOL AutomaticAllocation;
    XML_TYPE_BOOL AutomaticDeallocation;
    XML_TYPE_STR Parent;
    XML_TYPE_DYN_ARRAY Connection;
    XML_TYPE_STR Address;
    XML_TYPE_UINT16 MappingBehavior;
    XML_TYPE_DYN_ARRAY VirtualSystemIdentifiers;

} Msvm_ResourceAllocationSettingData_Data;
SER_DECLARE_TYPE(Msvm_ResourceAllocationSettingData_Data);
typedef struct _Msvm_ResourceAllocationSettingData {
    XmlSerializerInfo *serializerInfo;
    Msvm_ResourceAllocationSettingData_Data *data;
} Msvm_ResourceAllocationSettingData;

#define MSVM_RESOURCEALLOCATIONSETTINGDATA_RESOURCE_URI \
    "http://schemas.microsoft.com/wbem/wsman/1/wmi/root/virtualization/Msvm_ResourceAllocationSettingData"

#define MSVM_RESOURCEALLOCATIONSETTINGDATA_CLASSNAME \
    "Msvm_ResourceAllocationSettingData"

#define MSVM_RESOURCEALLOCATIONSETTINGDATA_WQL_SELECT \
    "select * from Msvm_ResourceAllocationSettingData "

class MsvmResourceAllocationSettingData : public AbstractWmiObject
{
public:
  MsvmResourceAllocationSettingData();
};
}
}
}
}
}
#endif /* V1_MSVM_RESOURCEALLOCATIONSETTINGDATA_H */

