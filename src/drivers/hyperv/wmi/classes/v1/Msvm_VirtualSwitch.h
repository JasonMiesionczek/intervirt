
#ifndef V1_MSVM_VIRTUALSWITCH_H
#define V1_MSVM_VIRTUALSWITCH_H

#include <common/util.h>
#include <drivers/hyperv/wmi/AbstractWmiObject.h>

namespace Drivers {
    namespace Hyperv {
        namespace Wmi {
            namespace Classes {
                namespace V1 {
                    typedef struct _Msvm_VirtualSwitch_Data {
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
                        XML_TYPE_STR CreationClassName;
                        XML_TYPE_STR Name;
                        XML_TYPE_STR PrimaryOwnerContact;
                        XML_TYPE_STR PrimaryOwnerName;
                        XML_TYPE_DYN_ARRAY Roles;
                        XML_TYPE_STR NameFormat;
                        XML_TYPE_DYN_ARRAY OtherIdentifyingInfo;
                        XML_TYPE_DYN_ARRAY IdentifyingDescriptions;
                        XML_TYPE_DYN_ARRAY Dedicated;
                        XML_TYPE_DYN_ARRAY OtherDedicatedDescriptions;
                        XML_TYPE_UINT16 ResetCapability;
                        XML_TYPE_DYN_ARRAY PowerManagementCapabilities;
                        XML_TYPE_STR ScopeOfResidence;
                        XML_TYPE_UINT32 NumLearnableAddresses;
                        XML_TYPE_UINT32 MaxVMQOffloads;
                        XML_TYPE_UINT32 MaxChimneyOffloads;

                    } Msvm_VirtualSwitch_Data;
                    
                    SER_DECLARE_TYPE(Msvm_VirtualSwitch_Data);
                    
                    typedef struct _Msvm_VirtualSwitch {
                        XmlSerializerInfo *serializerInfo;
                        Msvm_VirtualSwitch_Data *data;
                    } Msvm_VirtualSwitch;
                    
                    #define V1_MSVM_VIRTUALSWITCH_RESOURCE_URI \
                        "http://schemas.microsoft.com/wbem/wsman/1/wmi/root/virtualization/Msvm_VirtualSwitch"
                    
                    #define V1_MSVM_VIRTUALSWITCH_CLASSNAME \
                        "Msvm_VirtualSwitch"
                    
                    #define V1_MSVM_VIRTUALSWITCH_WQL_SELECT \
                        "select * from Msvm_VirtualSwitch "
                    
                    class MsvmVirtualSwitchMeta : public AbstractWmiObject
                    {
                    public:
                      MsvmVirtualSwitchMeta();
                    };
                }
            }
        }
    }
}

#endif /* V1_MSVM_VIRTUALSWITCH_H */

