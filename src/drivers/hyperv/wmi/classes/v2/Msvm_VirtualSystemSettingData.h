
#ifndef V2_MSVM_VIRTUALSYSTEMSETTINGDATA_H
#define V2_MSVM_VIRTUALSYSTEMSETTINGDATA_H

#include <common/util.h>
#include <drivers/hyperv/wmi/AbstractWmiObject.h>

namespace Drivers {
namespace Hyperv {
namespace Wmi {
namespace Classes {
namespace V2 {
typedef struct _Msvm_VirtualSystemSettingData_Data {
    XML_TYPE_STR InstanceID;
    XML_TYPE_STR Caption;
    XML_TYPE_STR Description;
    XML_TYPE_STR ElementName;
    XML_TYPE_STR VirtualSystemIdentifier;
    XML_TYPE_STR VirtualSystemType;
    XML_TYPE_DYN_ARRAY Notes;
    XML_TYPE_STR CreationTime;
    XML_TYPE_STR ConfigurationID;
    XML_TYPE_STR ConfigurationDataRoot;
    XML_TYPE_STR ConfigurationFile;
    XML_TYPE_STR SnapshotDataRoot;
    XML_TYPE_STR SuspendDataRoot;
    XML_TYPE_STR SwapFileDataRoot;
    XML_TYPE_STR LogDataRoot;
    XML_TYPE_UINT16 AutomaticStartupAction;
    XML_TYPE_STR AutomaticStartupActionDelay;
    XML_TYPE_UINT16 AutomaticStartupActionSequenceNumber;
    XML_TYPE_UINT16 AutomaticShutdownAction;
    XML_TYPE_UINT16 AutomaticRecoveryAction;
    XML_TYPE_STR RecoveryFile;
    XML_TYPE_STR BIOSGUID;
    XML_TYPE_STR BIOSSerialNumber;
    XML_TYPE_STR BaseBoardSerialNumber;
    XML_TYPE_STR ChassisSerialNumber;
    XML_TYPE_STR ChassisAssetTag;
    XML_TYPE_BOOL BIOSNumLock;
    XML_TYPE_DYN_ARRAY BootOrder;
    XML_TYPE_STR Parent;
    XML_TYPE_BOOL IsSaved;
    XML_TYPE_STR AdditionalRecoveryInformation;
    XML_TYPE_BOOL AllowFullSCSICommandSet;
    XML_TYPE_UINT32 DebugChannelId;
    XML_TYPE_UINT16 DebugPortEnabled;
    XML_TYPE_UINT32 DebugPort;
    XML_TYPE_STR Version;
    XML_TYPE_BOOL IncrementalBackupEnabled;
    XML_TYPE_BOOL VirtualNumaEnabled;
    XML_TYPE_BOOL AllowReducedFcRedundancy;
    XML_TYPE_STR VirtualSystemSubType;
    XML_TYPE_DYN_ARRAY BootSourceOrder;
    XML_TYPE_BOOL PauseAfterBootFailure;
    XML_TYPE_UINT16 NetworkBootPreferredProtocol;
    XML_TYPE_BOOL SecureBootEnabled;
    XML_TYPE_UINT64 LowMmioGapSize;

} Msvm_VirtualSystemSettingData_Data;
SER_DECLARE_TYPE(Msvm_VirtualSystemSettingData_Data);
typedef struct _Msvm_VirtualSystemSettingData {
    XmlSerializerInfo *serializerInfo;
    Msvm_VirtualSystemSettingData_Data *data;
} Msvm_VirtualSystemSettingData;

#define MSVM_VIRTUALSYSTEMSETTINGDATA_RESOURCE_URI \
    "http://schemas.microsoft.com/wbem/wsman/1/wmi/root/virtualization/v2/Msvm_VirtualSystemSettingData"

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
#endif /* V2_MSVM_VIRTUALSYSTEMSETTINGDATA_H */

