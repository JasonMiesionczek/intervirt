
#ifndef V1_MSVM_ALLOCATIONCAPABILITIES_H
#define V1_MSVM_ALLOCATIONCAPABILITIES_H

#include <common/util.h>
#include <drivers/hyperv/wmi/AbstractWmiObject.h>

namespace Drivers {
namespace Hyperv {
namespace Wmi {
namespace Classes {
namespace V1 {
typedef struct _Msvm_AllocationCapabilities_Data {
    XML_TYPE_STR Caption;
    XML_TYPE_STR Description;
    XML_TYPE_STR ElementName;
    XML_TYPE_STR InstanceID;
    XML_TYPE_STR OtherResourceType;
    XML_TYPE_UINT16 RequestTypesSupported;
    XML_TYPE_STR ResourceSubType;
    XML_TYPE_UINT16 ResourceType;
    XML_TYPE_UINT16 SharingMode;
    XML_TYPE_DYN_ARRAY SupportedAddStates;
    XML_TYPE_DYN_ARRAY SupportedRemoveStates;

} Msvm_AllocationCapabilities_Data;
SER_DECLARE_TYPE(Msvm_AllocationCapabilities_Data);
typedef struct _Msvm_AllocationCapabilities {
    XmlSerializerInfo *serializerInfo;
    Msvm_AllocationCapabilities_Data *data;
} Msvm_AllocationCapabilities;

#define V1_MSVM_ALLOCATIONCAPABILITIES_RESOURCE_URI \
    "http://schemas.microsoft.com/wbem/wsman/1/wmi/root/virtualization/Msvm_AllocationCapabilities"

#define V1_MSVM_ALLOCATIONCAPABILITIES_CLASSNAME \
    "Msvm_AllocationCapabilities"

#define V1_MSVM_ALLOCATIONCAPABILITIES_WQL_SELECT \
    "select * from Msvm_AllocationCapabilities "

class MsvmAllocationCapabilities : public AbstractWmiObject
{
public:
  MsvmAllocationCapabilities();
};
}
}
}
}
}
#endif /* V1_MSVM_ALLOCATIONCAPABILITIES_H */

