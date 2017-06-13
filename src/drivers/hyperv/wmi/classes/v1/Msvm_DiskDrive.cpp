
#include "Msvm_DiskDrive.h"

namespace Drivers {
    namespace Hyperv {
        namespace Wmi {
            namespace Classes {
                namespace V1 {

                    SER_START_ITEMS(Msvm_DiskDrive_Data)
                        SER_NS_STR(V1_MSVM_DISKDRIVE_RESOURCE_URI, "Caption", 1),
                        SER_NS_STR(V1_MSVM_DISKDRIVE_RESOURCE_URI, "Description", 1),
                        SER_NS_STR(V1_MSVM_DISKDRIVE_RESOURCE_URI, "ElementName", 1),
                        SER_NS_STR(V1_MSVM_DISKDRIVE_RESOURCE_URI, "InstallDate", 1),
                        SER_NS_STR(V1_MSVM_DISKDRIVE_RESOURCE_URI, "Name", 1),
                        SER_NS_DYN_ARRAY(V1_MSVM_DISKDRIVE_RESOURCE_URI, "OperationalStatus", 0, 0, uint16),
                        SER_NS_DYN_ARRAY(V1_MSVM_DISKDRIVE_RESOURCE_URI, "StatusDescriptions", 0, 0, string),
                        SER_NS_STR(V1_MSVM_DISKDRIVE_RESOURCE_URI, "Status", 1),
                        SER_NS_UINT16(V1_MSVM_DISKDRIVE_RESOURCE_URI, "HealthState", 1),
                        SER_NS_UINT16(V1_MSVM_DISKDRIVE_RESOURCE_URI, "EnabledState", 1),
                        SER_NS_STR(V1_MSVM_DISKDRIVE_RESOURCE_URI, "OtherEnabledState", 1),
                        SER_NS_UINT16(V1_MSVM_DISKDRIVE_RESOURCE_URI, "RequestedState", 1),
                        SER_NS_UINT16(V1_MSVM_DISKDRIVE_RESOURCE_URI, "EnabledDefault", 1),
                        SER_NS_STR(V1_MSVM_DISKDRIVE_RESOURCE_URI, "TimeOfLastStateChange", 1),
                        SER_NS_STR(V1_MSVM_DISKDRIVE_RESOURCE_URI, "SystemCreationClassName", 1),
                        SER_NS_STR(V1_MSVM_DISKDRIVE_RESOURCE_URI, "SystemName", 1),
                        SER_NS_STR(V1_MSVM_DISKDRIVE_RESOURCE_URI, "CreationClassName", 1),
                        SER_NS_STR(V1_MSVM_DISKDRIVE_RESOURCE_URI, "DeviceID", 1),
                        SER_NS_BOOL(V1_MSVM_DISKDRIVE_RESOURCE_URI, "PowerManagementSupported", 1),
                        SER_NS_DYN_ARRAY(V1_MSVM_DISKDRIVE_RESOURCE_URI, "PowerManagementCapabilities", 0, 0, uint16),
                        SER_NS_UINT16(V1_MSVM_DISKDRIVE_RESOURCE_URI, "Availability", 1),
                        SER_NS_UINT16(V1_MSVM_DISKDRIVE_RESOURCE_URI, "StatusInfo", 1),
                        SER_NS_UINT32(V1_MSVM_DISKDRIVE_RESOURCE_URI, "LastErrorCode", 1),
                        SER_NS_STR(V1_MSVM_DISKDRIVE_RESOURCE_URI, "ErrorDescription", 1),
                        SER_NS_BOOL(V1_MSVM_DISKDRIVE_RESOURCE_URI, "ErrorCleared", 1),
                        SER_NS_DYN_ARRAY(V1_MSVM_DISKDRIVE_RESOURCE_URI, "OtherIdentifyingInfo", 0, 0, string),
                        SER_NS_UINT64(V1_MSVM_DISKDRIVE_RESOURCE_URI, "PowerOnHours", 1),
                        SER_NS_UINT64(V1_MSVM_DISKDRIVE_RESOURCE_URI, "TotalPowerOnHours", 1),
                        SER_NS_DYN_ARRAY(V1_MSVM_DISKDRIVE_RESOURCE_URI, "IdentifyingDescriptions", 0, 0, string),
                        SER_NS_DYN_ARRAY(V1_MSVM_DISKDRIVE_RESOURCE_URI, "AdditionalAvailability", 0, 0, uint16),
                        SER_NS_UINT64(V1_MSVM_DISKDRIVE_RESOURCE_URI, "MaxQuiesceTime", 1),
                        SER_NS_UINT16(V1_MSVM_DISKDRIVE_RESOURCE_URI, "LocationIndicator", 1),
                        SER_NS_DYN_ARRAY(V1_MSVM_DISKDRIVE_RESOURCE_URI, "Capabilities", 0, 0, uint16),
                        SER_NS_DYN_ARRAY(V1_MSVM_DISKDRIVE_RESOURCE_URI, "CapabilityDescriptions", 0, 0, string),
                        SER_NS_STR(V1_MSVM_DISKDRIVE_RESOURCE_URI, "ErrorMethodology", 1),
                        SER_NS_STR(V1_MSVM_DISKDRIVE_RESOURCE_URI, "CompressionMethod", 1),
                        SER_NS_UINT32(V1_MSVM_DISKDRIVE_RESOURCE_URI, "NumberOfMediaSupported", 1),
                        SER_NS_UINT64(V1_MSVM_DISKDRIVE_RESOURCE_URI, "MaxMediaSize", 1),
                        SER_NS_UINT64(V1_MSVM_DISKDRIVE_RESOURCE_URI, "DefaultBlockSize", 1),
                        SER_NS_UINT64(V1_MSVM_DISKDRIVE_RESOURCE_URI, "MaxBlockSize", 1),
                        SER_NS_UINT64(V1_MSVM_DISKDRIVE_RESOURCE_URI, "MinBlockSize", 1),
                        SER_NS_BOOL(V1_MSVM_DISKDRIVE_RESOURCE_URI, "NeedsCleaning", 1),
                        SER_NS_BOOL(V1_MSVM_DISKDRIVE_RESOURCE_URI, "MediaIsLocked", 1),
                        SER_NS_UINT16(V1_MSVM_DISKDRIVE_RESOURCE_URI, "Security", 1),
                        SER_NS_STR(V1_MSVM_DISKDRIVE_RESOURCE_URI, "LastCleaned", 1),
                        SER_NS_UINT64(V1_MSVM_DISKDRIVE_RESOURCE_URI, "MaxAccessTime", 1),
                        SER_NS_UINT32(V1_MSVM_DISKDRIVE_RESOURCE_URI, "UncompressedDataRate", 1),
                        SER_NS_UINT64(V1_MSVM_DISKDRIVE_RESOURCE_URI, "LoadTime", 1),
                        SER_NS_UINT64(V1_MSVM_DISKDRIVE_RESOURCE_URI, "UnloadTime", 1),
                        SER_NS_UINT64(V1_MSVM_DISKDRIVE_RESOURCE_URI, "MountCount", 1),
                        SER_NS_STR(V1_MSVM_DISKDRIVE_RESOURCE_URI, "TimeOfLastMount", 1),
                        SER_NS_UINT64(V1_MSVM_DISKDRIVE_RESOURCE_URI, "TotalMountTime", 1),
                        SER_NS_STR(V1_MSVM_DISKDRIVE_RESOURCE_URI, "UnitsDescription", 1),
                        SER_NS_UINT64(V1_MSVM_DISKDRIVE_RESOURCE_URI, "MaxUnitsBeforeCleaning", 1),
                        SER_NS_UINT64(V1_MSVM_DISKDRIVE_RESOURCE_URI, "UnitsUsed", 1),
                        SER_NS_UINT32(V1_MSVM_DISKDRIVE_RESOURCE_URI, "DriveNumber", 1),

                    SER_END_ITEMS(Msvm_DiskDrive_Data);
                    
                    MsvmDiskDriveMeta::MsvmDiskDriveMeta()
                            :AbstractWmiObject(
                                V1_MSVM_DISKDRIVE_WQL_SELECT,
                                V1_MSVM_DISKDRIVE_CLASSNAME,
                                "http://schemas.microsoft.com/wbem/wsman/1/wmi/root/virtualization/*",
                                V1_MSVM_DISKDRIVE_RESOURCE_URI,
                                Msvm_DiskDrive_Data_TypeInfo
                            ) {}

                }
            }
        }
    }
}
