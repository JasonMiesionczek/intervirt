
#include "Msvm_VirtualHardDiskSettingData.h"

namespace Drivers {
namespace Hyperv {
namespace Wmi {
namespace Classes {
namespace V1 {


SER_START_ITEMS(Msvm_VirtualHardDiskSettingData_Data)
    SER_NS_STR(MSVM_VIRTUALHARDDISKSETTINGDATA_RESOURCE_URI, "InstanceID", 1),
    SER_NS_STR(MSVM_VIRTUALHARDDISKSETTINGDATA_RESOURCE_URI, "Caption", 1),
    SER_NS_STR(MSVM_VIRTUALHARDDISKSETTINGDATA_RESOURCE_URI, "Description", 1),
    SER_NS_STR(MSVM_VIRTUALHARDDISKSETTINGDATA_RESOURCE_URI, "ElementName", 1),
    SER_NS_UINT16(MSVM_VIRTUALHARDDISKSETTINGDATA_RESOURCE_URI, "Type", 1),
    SER_NS_UINT16(MSVM_VIRTUALHARDDISKSETTINGDATA_RESOURCE_URI, "Format", 1),
    SER_NS_STR(MSVM_VIRTUALHARDDISKSETTINGDATA_RESOURCE_URI, "Path", 1),
    SER_NS_STR(MSVM_VIRTUALHARDDISKSETTINGDATA_RESOURCE_URI, "ParentPath", 1),
    SER_NS_UINT64(MSVM_VIRTUALHARDDISKSETTINGDATA_RESOURCE_URI, "MaxInternalSize", 1),
    SER_NS_UINT32(MSVM_VIRTUALHARDDISKSETTINGDATA_RESOURCE_URI, "BlockSize", 1),
    SER_NS_UINT32(MSVM_VIRTUALHARDDISKSETTINGDATA_RESOURCE_URI, "LogicalSectorSize", 1),
    SER_NS_UINT32(MSVM_VIRTUALHARDDISKSETTINGDATA_RESOURCE_URI, "PhysicalSectorSize", 1),
    SER_NS_STR(MSVM_VIRTUALHARDDISKSETTINGDATA_RESOURCE_URI, "VirtualDiskId", 1),

SER_END_ITEMS(Msvm_VirtualHardDiskSettingData_Data);

MsvmVirtualHardDiskSettingData::MsvmVirtualHardDiskSettingData()
        :AbstractWmiObject(
            MSVM_VIRTUALHARDDISKSETTINGDATA_WQL_SELECT,
            MSVM_VIRTUALHARDDISKSETTINGDATA_CLASSNAME,
            "",
            MSVM_VIRTUALHARDDISKSETTINGDATA_RESOURCE_URI,
            Msvm_VirtualHardDiskSettingData_Data_TypeInfo
        ) {}

}
}
}
}
}
