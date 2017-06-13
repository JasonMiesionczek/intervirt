
#include "Msvm_VirtualHardDiskSettingData.h"

namespace Drivers {
    namespace Hyperv {
        namespace Wmi {
            namespace Classes {
                namespace V1 {

                    SER_START_ITEMS(Msvm_VirtualHardDiskSettingData_Data)
                        SER_NS_STR(V1_MSVM_VIRTUALHARDDISKSETTINGDATA_RESOURCE_URI, "InstanceID", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALHARDDISKSETTINGDATA_RESOURCE_URI, "Caption", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALHARDDISKSETTINGDATA_RESOURCE_URI, "Description", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALHARDDISKSETTINGDATA_RESOURCE_URI, "ElementName", 1),
                        SER_NS_UINT16(V1_MSVM_VIRTUALHARDDISKSETTINGDATA_RESOURCE_URI, "Type", 1),
                        SER_NS_UINT16(V1_MSVM_VIRTUALHARDDISKSETTINGDATA_RESOURCE_URI, "Format", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALHARDDISKSETTINGDATA_RESOURCE_URI, "Path", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALHARDDISKSETTINGDATA_RESOURCE_URI, "ParentPath", 1),
                        SER_NS_UINT64(V1_MSVM_VIRTUALHARDDISKSETTINGDATA_RESOURCE_URI, "MaxInternalSize", 1),
                        SER_NS_UINT32(V1_MSVM_VIRTUALHARDDISKSETTINGDATA_RESOURCE_URI, "BlockSize", 1),
                        SER_NS_UINT32(V1_MSVM_VIRTUALHARDDISKSETTINGDATA_RESOURCE_URI, "LogicalSectorSize", 1),
                        SER_NS_UINT32(V1_MSVM_VIRTUALHARDDISKSETTINGDATA_RESOURCE_URI, "PhysicalSectorSize", 1),
                        SER_NS_STR(V1_MSVM_VIRTUALHARDDISKSETTINGDATA_RESOURCE_URI, "VirtualDiskId", 1),

                    SER_END_ITEMS(Msvm_VirtualHardDiskSettingData_Data);
                    
                    MsvmVirtualHardDiskSettingDataMeta::MsvmVirtualHardDiskSettingDataMeta()
                            :AbstractWmiObject(
                                V1_MSVM_VIRTUALHARDDISKSETTINGDATA_WQL_SELECT,
                                V1_MSVM_VIRTUALHARDDISKSETTINGDATA_CLASSNAME,
                                "http://schemas.microsoft.com/wbem/wsman/1/wmi/root/virtualization/*",
                                V1_MSVM_VIRTUALHARDDISKSETTINGDATA_RESOURCE_URI,
                                Msvm_VirtualHardDiskSettingData_Data_TypeInfo
                            ) {}

                }
            }
        }
    }
}
