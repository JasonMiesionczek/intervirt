
#ifndef V1_MSVM_VIRTUALHARDDISKSETTINGDATA_H
#define V1_MSVM_VIRTUALHARDDISKSETTINGDATA_H

#include <common/util.h>
#include <drivers/hyperv/wmi/AbstractWmiObject.h>

namespace Drivers {
namespace Hyperv {
namespace Wmi {
namespace Classes {
namespace V1 {
typedef struct _Msvm_VirtualHardDiskSettingData_Data {
    XML_TYPE_STR InstanceID;
    XML_TYPE_STR Caption;
    XML_TYPE_STR Description;
    XML_TYPE_STR ElementName;
    XML_TYPE_UINT16 Type;
    XML_TYPE_UINT16 Format;
    XML_TYPE_STR Path;
    XML_TYPE_STR ParentPath;
    XML_TYPE_UINT64 MaxInternalSize;
    XML_TYPE_UINT32 BlockSize;
    XML_TYPE_UINT32 LogicalSectorSize;
    XML_TYPE_UINT32 PhysicalSectorSize;
    XML_TYPE_STR VirtualDiskId;

} Msvm_VirtualHardDiskSettingData_Data;
SER_DECLARE_TYPE(Msvm_VirtualHardDiskSettingData_Data);
typedef struct _Msvm_VirtualHardDiskSettingData {
    XmlSerializerInfo *serializerInfo;
    Msvm_VirtualHardDiskSettingData_Data *data;
} Msvm_VirtualHardDiskSettingData;

#define MSVM_VIRTUALHARDDISKSETTINGDATA_RESOURCE_URI \
    "http://schemas.microsoft.com/wbem/wsman/1/wmi/root/virtualization/Msvm_VirtualHardDiskSettingData"

#define MSVM_VIRTUALHARDDISKSETTINGDATA_CLASSNAME \
    "Msvm_VirtualHardDiskSettingData"

#define MSVM_VIRTUALHARDDISKSETTINGDATA_WQL_SELECT \
    "select * from Msvm_VirtualHardDiskSettingData "

class MsvmVirtualHardDiskSettingData : public AbstractWmiObject
{
public:
  MsvmVirtualHardDiskSettingData();
};
}
}
}
}
}
#endif /* V1_MSVM_VIRTUALHARDDISKSETTINGDATA_H */

