
#ifndef V2_MSVM_MEMORYSETTINGDATA_H
#define V2_MSVM_MEMORYSETTINGDATA_H

#include <common/util.h>
#include <drivers/hyperv/wmi/AbstractWmiObject.h>

namespace Drivers {
namespace Hyperv {
namespace Wmi {
namespace Classes {
namespace V2 {
typedef struct _Msvm_MemorySettingData_Data {
    XML_TYPE_STR InstanceID;
    XML_TYPE_STR Caption;
    XML_TYPE_STR Description;
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
    XML_TYPE_STR AddressOnParent;
    XML_TYPE_STR VirtualQuantityUnits;
    XML_TYPE_BOOL DynamicMemoryEnabled;
    XML_TYPE_UINT32 TargetMemoryBuffer;
    XML_TYPE_BOOL IsVirtualized;
    XML_TYPE_BOOL SwapFilesInUse;
    XML_TYPE_UINT64 MaxMemoryBlocksPerNumaNode;

} Msvm_MemorySettingData_Data;
SER_DECLARE_TYPE(Msvm_MemorySettingData_Data);
typedef struct _Msvm_MemorySettingData {
    XmlSerializerInfo *serializerInfo;
    Msvm_MemorySettingData_Data *data;
} Msvm_MemorySettingData;

#define V2_MSVM_MEMORYSETTINGDATA_RESOURCE_URI \
    "http://schemas.microsoft.com/wbem/wsman/1/wmi/root/virtualization/v2/Msvm_MemorySettingData"

#define V2_MSVM_MEMORYSETTINGDATA_CLASSNAME \
    "Msvm_MemorySettingData"

#define V2_MSVM_MEMORYSETTINGDATA_WQL_SELECT \
    "select * from Msvm_MemorySettingData "

class MsvmMemorySettingData : public AbstractWmiObject
{
public:
  MsvmMemorySettingData();
};
}
}
}
}
}
#endif /* V2_MSVM_MEMORYSETTINGDATA_H */

