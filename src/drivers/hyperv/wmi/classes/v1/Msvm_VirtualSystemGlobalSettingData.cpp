
#include "Msvm_VirtualSystemGlobalSettingData.h"

namespace Drivers {
    namespace Hyperv {
        namespace Wmi {
            namespace Classes {
                namespace V1 {

                    SER_START_ITEMS(Msvm_VirtualSystemGlobalSettingData_Data)
                        SER_NS_STR(V1_MSVM_VIRTUALSYSTEMGLOBALSETTINGDATA_RESOURCE_URI, "Caption", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALSYSTEMGLOBALSETTINGDATA_RESOURCE_URI, "Description", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALSYSTEMGLOBALSETTINGDATA_RESOURCE_URI, "ElementName", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALSYSTEMGLOBALSETTINGDATA_RESOURCE_URI, "InstanceID", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALSYSTEMGLOBALSETTINGDATA_RESOURCE_URI, "SystemName", 1),
                        SER_NS_UINT16(V1_MSVM_VIRTUALSYSTEMGLOBALSETTINGDATA_RESOURCE_URI, "SettingType", 1),
                        SER_NS_UINT16(V1_MSVM_VIRTUALSYSTEMGLOBALSETTINGDATA_RESOURCE_URI, "VirtualSystemType", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALSYSTEMGLOBALSETTINGDATA_RESOURCE_URI, "OtherVirtualSystemType", 1),
                        SER_NS_BOOL(V1_MSVM_VIRTUALSYSTEMGLOBALSETTINGDATA_RESOURCE_URI, "AutoActivate", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALSYSTEMGLOBALSETTINGDATA_RESOURCE_URI, "CreationTime", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALSYSTEMGLOBALSETTINGDATA_RESOURCE_URI, "ExternalDataRoot", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALSYSTEMGLOBALSETTINGDATA_RESOURCE_URI, "SnapshotDataRoot", 1),
                        SER_NS_UINT16(V1_MSVM_VIRTUALSYSTEMGLOBALSETTINGDATA_RESOURCE_URI, "AutomaticStartupAction", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALSYSTEMGLOBALSETTINGDATA_RESOURCE_URI, "AutomaticStartupActionDelay", 1),
                        SER_NS_UINT16(V1_MSVM_VIRTUALSYSTEMGLOBALSETTINGDATA_RESOURCE_URI, "AutomaticShutdownAction", 1),
                        SER_NS_UINT16(V1_MSVM_VIRTUALSYSTEMGLOBALSETTINGDATA_RESOURCE_URI, "AutomaticRecoveryAction", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALSYSTEMGLOBALSETTINGDATA_RESOURCE_URI, "AdditionalRecoveryInformation", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALSYSTEMGLOBALSETTINGDATA_RESOURCE_URI, "ScopeOfResidence", 1),
                        SER_NS_UINT32(V1_MSVM_VIRTUALSYSTEMGLOBALSETTINGDATA_RESOURCE_URI, "DebugChannelId", 1),
                        SER_NS_BOOL(V1_MSVM_VIRTUALSYSTEMGLOBALSETTINGDATA_RESOURCE_URI, "AllowFullSCSICommandSet", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALSYSTEMGLOBALSETTINGDATA_RESOURCE_URI, "Version", 1),

                    SER_END_ITEMS(Msvm_VirtualSystemGlobalSettingData_Data);
                    
                    MsvmVirtualSystemGlobalSettingDataMeta::MsvmVirtualSystemGlobalSettingDataMeta()
                            :AbstractWmiObject(
                                V1_MSVM_VIRTUALSYSTEMGLOBALSETTINGDATA_WQL_SELECT,
                                V1_MSVM_VIRTUALSYSTEMGLOBALSETTINGDATA_CLASSNAME,
                                "http://schemas.microsoft.com/wbem/wsman/1/wmi/root/virtualization/*",
                                V1_MSVM_VIRTUALSYSTEMGLOBALSETTINGDATA_RESOURCE_URI,
                                Msvm_VirtualSystemGlobalSettingData_Data_TypeInfo
                            ) {}

                }
            }
        }
    }
}
