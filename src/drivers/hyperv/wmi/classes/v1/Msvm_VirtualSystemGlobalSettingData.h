
#ifndef V1_MSVM_VIRTUALSYSTEMGLOBALSETTINGDATA_H
#define V1_MSVM_VIRTUALSYSTEMGLOBALSETTINGDATA_H

#include <common/util.h>
#include <drivers/hyperv/wmi/AbstractWmiObject.h>

namespace Drivers {
namespace Hyperv {
namespace Wmi {
namespace Classes {
namespace V1 {
typedef struct _Msvm_VirtualSystemGlobalSettingData_Data {
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
    XML_TYPE_STR ExternalDataRoot;
    XML_TYPE_STR SnapshotDataRoot;
    XML_TYPE_UINT16 AutomaticStartupAction;
    XML_TYPE_STR AutomaticStartupActionDelay;
    XML_TYPE_UINT16 AutomaticShutdownAction;
    XML_TYPE_UINT16 AutomaticRecoveryAction;
    XML_TYPE_STR AdditionalRecoveryInformation;
    XML_TYPE_STR ScopeOfResidence;
    XML_TYPE_UINT32 DebugChannelId;
    XML_TYPE_BOOL AllowFullSCSICommandSet;
    XML_TYPE_STR Version;

} Msvm_VirtualSystemGlobalSettingData_Data;
SER_DECLARE_TYPE(Msvm_VirtualSystemGlobalSettingData_Data);
typedef struct _Msvm_VirtualSystemGlobalSettingData {
    XmlSerializerInfo *serializerInfo;
    Msvm_VirtualSystemGlobalSettingData_Data *data;
} Msvm_VirtualSystemGlobalSettingData;

#define MSVM_VIRTUALSYSTEMGLOBALSETTINGDATA_RESOURCE_URI \
    "http://schemas.microsoft.com/wbem/wsman/1/wmi/root/virtualization/Msvm_VirtualSystemGlobalSettingData"

#define MSVM_VIRTUALSYSTEMGLOBALSETTINGDATA_CLASSNAME \
    "Msvm_VirtualSystemGlobalSettingData"

#define MSVM_VIRTUALSYSTEMGLOBALSETTINGDATA_WQL_SELECT \
    "select * from Msvm_VirtualSystemGlobalSettingData "

class MsvmVirtualSystemGlobalSettingData : public AbstractWmiObject
{
public:
  MsvmVirtualSystemGlobalSettingData();
};
}
}
}
}
}
#endif /* V1_MSVM_VIRTUALSYSTEMGLOBALSETTINGDATA_H */

