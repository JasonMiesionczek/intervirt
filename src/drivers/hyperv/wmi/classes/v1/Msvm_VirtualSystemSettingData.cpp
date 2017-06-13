
#include "Msvm_VirtualSystemSettingData.h"

namespace Drivers {
    namespace Hyperv {
        namespace Wmi {
            namespace Classes {
                namespace V1 {

                    SER_START_ITEMS(Msvm_VirtualSystemSettingData_Data)
                        SER_NS_STR(V1_MSVM_VIRTUALSYSTEMSETTINGDATA_RESOURCE_URI, "Caption", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALSYSTEMSETTINGDATA_RESOURCE_URI, "Description", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALSYSTEMSETTINGDATA_RESOURCE_URI, "ElementName", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALSYSTEMSETTINGDATA_RESOURCE_URI, "InstanceID", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALSYSTEMSETTINGDATA_RESOURCE_URI, "SystemName", 1),
                        SER_NS_UINT16(V1_MSVM_VIRTUALSYSTEMSETTINGDATA_RESOURCE_URI, "SettingType", 1),
                        SER_NS_UINT16(V1_MSVM_VIRTUALSYSTEMSETTINGDATA_RESOURCE_URI, "VirtualSystemType", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALSYSTEMSETTINGDATA_RESOURCE_URI, "OtherVirtualSystemType", 1),
                        SER_NS_BOOL(V1_MSVM_VIRTUALSYSTEMSETTINGDATA_RESOURCE_URI, "AutoActivate", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALSYSTEMSETTINGDATA_RESOURCE_URI, "CreationTime", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALSYSTEMSETTINGDATA_RESOURCE_URI, "Notes", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALSYSTEMSETTINGDATA_RESOURCE_URI, "BIOSGUID", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALSYSTEMSETTINGDATA_RESOURCE_URI, "BIOSSerialNumber", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALSYSTEMSETTINGDATA_RESOURCE_URI, "BaseBoardSerialNumber", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALSYSTEMSETTINGDATA_RESOURCE_URI, "ChassisSerialNumber", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALSYSTEMSETTINGDATA_RESOURCE_URI, "ChassisAssetTag", 1),
                        SER_NS_BOOL(V1_MSVM_VIRTUALSYSTEMSETTINGDATA_RESOURCE_URI, "BIOSNumLock", 1),
                        SER_NS_DYN_ARRAY(V1_MSVM_VIRTUALSYSTEMSETTINGDATA_RESOURCE_URI, "BootOrder", 0, 0, uint16),
                        SER_NS_STR(V1_MSVM_VIRTUALSYSTEMSETTINGDATA_RESOURCE_URI, "Parent", 1),
                        SER_NS_DYN_ARRAY(V1_MSVM_VIRTUALSYSTEMSETTINGDATA_RESOURCE_URI, "NumaNodeList", 0, 0, uint16),
                        SER_NS_BOOL(V1_MSVM_VIRTUALSYSTEMSETTINGDATA_RESOURCE_URI, "NumaNodesAreRequired", 1),

                    SER_END_ITEMS(Msvm_VirtualSystemSettingData_Data);
                    
                    MsvmVirtualSystemSettingDataMeta::MsvmVirtualSystemSettingDataMeta()
                            :AbstractWmiObject(
                                V1_MSVM_VIRTUALSYSTEMSETTINGDATA_WQL_SELECT,
                                V1_MSVM_VIRTUALSYSTEMSETTINGDATA_CLASSNAME,
                                "http://schemas.microsoft.com/wbem/wsman/1/wmi/root/virtualization/*",
                                V1_MSVM_VIRTUALSYSTEMSETTINGDATA_RESOURCE_URI,
                                Msvm_VirtualSystemSettingData_Data_TypeInfo
                            ) {}

                }
            }
        }
    }
}
