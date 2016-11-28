
#ifndef V1_MSVM_DISKDRIVE_H
#define V1_MSVM_DISKDRIVE_H

#include <common/util.h>
#include <drivers/hyperv/wmi/AbstractWmiObject.h>

namespace Drivers {
namespace Hyperv {
namespace Wmi {
namespace Classes {
namespace V1 {
typedef struct _Msvm_DiskDrive_Data {
    XML_TYPE_STR Caption;
    XML_TYPE_STR Description;
    XML_TYPE_STR ElementName;
    XML_TYPE_STR InstallDate;
    XML_TYPE_STR Name;
    XML_TYPE_DYN_ARRAY OperationalStatus;
    XML_TYPE_DYN_ARRAY StatusDescriptions;
    XML_TYPE_STR Status;
    XML_TYPE_UINT16 HealthState;
    XML_TYPE_UINT16 EnabledState;
    XML_TYPE_STR OtherEnabledState;
    XML_TYPE_UINT16 RequestedState;
    XML_TYPE_UINT16 EnabledDefault;
    XML_TYPE_STR TimeOfLastStateChange;
    XML_TYPE_STR SystemCreationClassName;
    XML_TYPE_STR SystemName;
    XML_TYPE_STR CreationClassName;
    XML_TYPE_STR DeviceID;
    XML_TYPE_BOOL PowerManagementSupported;
    XML_TYPE_DYN_ARRAY PowerManagementCapabilities;
    XML_TYPE_UINT16 Availability;
    XML_TYPE_UINT16 StatusInfo;
    XML_TYPE_UINT32 LastErrorCode;
    XML_TYPE_STR ErrorDescription;
    XML_TYPE_BOOL ErrorCleared;
    XML_TYPE_DYN_ARRAY OtherIdentifyingInfo;
    XML_TYPE_UINT64 PowerOnHours;
    XML_TYPE_UINT64 TotalPowerOnHours;
    XML_TYPE_DYN_ARRAY IdentifyingDescriptions;
    XML_TYPE_DYN_ARRAY AdditionalAvailability;
    XML_TYPE_UINT64 MaxQuiesceTime;
    XML_TYPE_UINT16 LocationIndicator;
    XML_TYPE_DYN_ARRAY Capabilities;
    XML_TYPE_DYN_ARRAY CapabilityDescriptions;
    XML_TYPE_STR ErrorMethodology;
    XML_TYPE_STR CompressionMethod;
    XML_TYPE_UINT32 NumberOfMediaSupported;
    XML_TYPE_UINT64 MaxMediaSize;
    XML_TYPE_UINT64 DefaultBlockSize;
    XML_TYPE_UINT64 MaxBlockSize;
    XML_TYPE_UINT64 MinBlockSize;
    XML_TYPE_BOOL NeedsCleaning;
    XML_TYPE_BOOL MediaIsLocked;
    XML_TYPE_UINT16 Security;
    XML_TYPE_STR LastCleaned;
    XML_TYPE_UINT64 MaxAccessTime;
    XML_TYPE_UINT32 UncompressedDataRate;
    XML_TYPE_UINT64 LoadTime;
    XML_TYPE_UINT64 UnloadTime;
    XML_TYPE_UINT64 MountCount;
    XML_TYPE_STR TimeOfLastMount;
    XML_TYPE_UINT64 TotalMountTime;
    XML_TYPE_STR UnitsDescription;
    XML_TYPE_UINT64 MaxUnitsBeforeCleaning;
    XML_TYPE_UINT64 UnitsUsed;
    XML_TYPE_UINT32 DriveNumber;

} Msvm_DiskDrive_Data;
SER_DECLARE_TYPE(Msvm_DiskDrive_Data);
typedef struct _Msvm_DiskDrive {
    XmlSerializerInfo *serializerInfo;
    Msvm_DiskDrive_Data *data;
} Msvm_DiskDrive;

#define MSVM_DISKDRIVE_RESOURCE_URI \
    "http://schemas.microsoft.com/wbem/wsman/1/wmi/root/virtualization/Msvm_DiskDrive"

#define MSVM_DISKDRIVE_CLASSNAME \
    "Msvm_DiskDrive"

#define MSVM_DISKDRIVE_WQL_SELECT \
    "select * from Msvm_DiskDrive "

class MsvmDiskDrive : public AbstractWmiObject
{
public:
  MsvmDiskDrive();
};
}
}
}
}
}
#endif /* V1_MSVM_DISKDRIVE_H */

