
#ifndef V2_MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_H
#define V2_MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_H

#include <common/util.h>
#include <drivers/hyperv/wmi/AbstractWmiObject.h>

namespace Drivers {
namespace Hyperv {
namespace Wmi {
namespace Classes {
namespace V2 {
typedef struct _Msvm_VirtualSystemManagementService_Data {
    XML_TYPE_STR InstanceID;
    XML_TYPE_STR Caption;
    XML_TYPE_STR Description;
    XML_TYPE_STR ElementName;
    XML_TYPE_STR InstallDate;
    XML_TYPE_STR Name;
    XML_TYPE_DYN_ARRAY OperationalStatus;
    XML_TYPE_DYN_ARRAY StatusDescriptions;
    XML_TYPE_STR Status;
    XML_TYPE_UINT16 HealthState;
    XML_TYPE_UINT16 CommunicationStatus;
    XML_TYPE_UINT16 DetailedStatus;
    XML_TYPE_UINT16 OperatingStatus;
    XML_TYPE_UINT16 PrimaryStatus;
    XML_TYPE_UINT16 EnabledState;
    XML_TYPE_STR OtherEnabledState;
    XML_TYPE_UINT16 RequestedState;
    XML_TYPE_UINT16 EnabledDefault;
    XML_TYPE_STR TimeOfLastStateChange;
    XML_TYPE_DYN_ARRAY AvailableRequestedStates;
    XML_TYPE_UINT16 TransitioningToState;
    XML_TYPE_STR SystemCreationClassName;
    XML_TYPE_STR SystemName;
    XML_TYPE_STR CreationClassName;
    XML_TYPE_STR PrimaryOwnerName;
    XML_TYPE_STR PrimaryOwnerContact;
    XML_TYPE_STR StartMode;
    XML_TYPE_BOOL Started;

} Msvm_VirtualSystemManagementService_Data;
SER_DECLARE_TYPE(Msvm_VirtualSystemManagementService_Data);
typedef struct _Msvm_VirtualSystemManagementService {
    XmlSerializerInfo *serializerInfo;
    Msvm_VirtualSystemManagementService_Data *data;
} Msvm_VirtualSystemManagementService;

#define MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_RESOURCE_URI \
    "http://schemas.microsoft.com/wbem/wsman/1/wmi/root/virtualization/v2/Msvm_VirtualSystemManagementService"

#define MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_CLASSNAME \
    "Msvm_VirtualSystemManagementService"

#define MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_WQL_SELECT \
    "select * from Msvm_VirtualSystemManagementService "

class MsvmVirtualSystemManagementService : public AbstractWmiObject
{
public:
  MsvmVirtualSystemManagementService();
};
}
}
}
}
}
#endif /* V2_MSVM_VIRTUALSYSTEMMANAGEMENTSERVICE_H */

