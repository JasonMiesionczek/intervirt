
#ifndef V1_MSVM_VIRTUALSWITCHMANAGEMENTSERVICE_H
#define V1_MSVM_VIRTUALSWITCHMANAGEMENTSERVICE_H

#include <common/util.h>
#include <drivers/hyperv/wmi/AbstractWmiObject.h>

namespace Drivers {
namespace Hyperv {
namespace Wmi {
namespace Classes {
namespace V1 {
typedef struct _Msvm_VirtualSwitchManagementService_Data {
    XML_TYPE_STR Caption;
    XML_TYPE_STR Description;
    XML_TYPE_STR ElementName;
    XML_TYPE_STR InstallDate;
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
    XML_TYPE_STR Name;
    XML_TYPE_STR PrimaryOwnerName;
    XML_TYPE_STR PrimaryOwnerContact;
    XML_TYPE_STR StartMode;
    XML_TYPE_BOOL Started;

} Msvm_VirtualSwitchManagementService_Data;
SER_DECLARE_TYPE(Msvm_VirtualSwitchManagementService_Data);
typedef struct _Msvm_VirtualSwitchManagementService {
    XmlSerializerInfo *serializerInfo;
    Msvm_VirtualSwitchManagementService_Data *data;
} Msvm_VirtualSwitchManagementService;

#define MSVM_VIRTUALSWITCHMANAGEMENTSERVICE_RESOURCE_URI \
    "http://schemas.microsoft.com/wbem/wsman/1/wmi/root/virtualization/Msvm_VirtualSwitchManagementService"

#define MSVM_VIRTUALSWITCHMANAGEMENTSERVICE_CLASSNAME \
    "Msvm_VirtualSwitchManagementService"

#define MSVM_VIRTUALSWITCHMANAGEMENTSERVICE_WQL_SELECT \
    "select * from Msvm_VirtualSwitchManagementService "

class MsvmVirtualSwitchManagementService : public AbstractWmiObject
{
public:
  MsvmVirtualSwitchManagementService();
};
}
}
}
}
}
#endif /* V1_MSVM_VIRTUALSWITCHMANAGEMENTSERVICE_H */

