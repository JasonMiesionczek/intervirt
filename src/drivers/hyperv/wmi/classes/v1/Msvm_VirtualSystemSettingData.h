
#ifndef V1_MSVM_VIRTUALSYSTEMSETTINGDATA_H
#define V1_MSVM_VIRTUALSYSTEMSETTINGDATA_H

#include <common/util.h>
#include <drivers/hyperv/wmi/AbstractWmiObject.h>

namespace Drivers {
namespace Hyperv {
namespace Wmi {
namespace Classes {
namespace V1 {
typedef struct _Msvm_VirtualSystemSettingData_Data {
    XML_TYPE_STR Caption;
    XML_TYPE_STR Description;
    XML_TYPE_STR ElementName;
    XML_TYPE_STR InstanceID;
    XML_TYPE_STR SystemName;
    XML_TYPE_UINT16 SettingType;
    XML_TYPE_UINT16 VirtualSystemType;
    XML_TYPE_STR OtherVirtualSystemType;
    XML_TYPE_BOOL AutoActivate;
    XML_TYPE_STR CreationTime;
    XML_TYPE_STR Notes;
    XML_TYPE_STR BIOSGUID;
    XML_TYPE_STR BIOSSerialNumber;
    XML_TYPE_STR BaseBoardSerialNumber;
    XML_TYPE_STR ChassisSerialNumber;
    XML_TYPE_STR ChassisAssetTag;
    XML_TYPE_BOOL BIOSNumLock;
    XML_TYPE_DYN_ARRAY BootOrder;
    XML_TYPE_STR Parent;
    XML_TYPE_DYN_ARRAY NumaNodeList;
    XML_TYPE_BOOL NumaNodesAreRequired;

} Msvm_VirtualSystemSettingData_Data;
SER_DECLARE_TYPE(Msvm_VirtualSystemSettingData_Data);
typedef struct _Msvm_VirtualSystemSettingData {
    XmlSerializerInfo *serializerInfo;
    Msvm_VirtualSystemSettingData_Data *data;
} Msvm_VirtualSystemSettingData;

#define MSVM_VIRTUALSYSTEMSETTINGDATA_RESOURCE_URI \
    "http://schemas.microsoft.com/wbem/wsman/1/wmi/root/virtualization/Msvm_VirtualSystemSettingData"

#define MSVM_VIRTUALSYSTEMSETTINGDATA_CLASSNAME \
    "Msvm_VirtualSystemSettingData"

#define MSVM_VIRTUALSYSTEMSETTINGDATA_WQL_SELECT \
    "select * from Msvm_VirtualSystemSettingData "

class MsvmVirtualSystemSettingData : public AbstractWmiObject
{
public:
  MsvmVirtualSystemSettingData();
};
}
}
}
}
}
#endif /* V1_MSVM_VIRTUALSYSTEMSETTINGDATA_H */

