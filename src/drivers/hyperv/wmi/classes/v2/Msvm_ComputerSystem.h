
#ifndef V2_MSVM_COMPUTERSYSTEM_H
#define V2_MSVM_COMPUTERSYSTEM_H

#include <common/util.h>
#include <drivers/hyperv/wmi/AbstractWmiObject.h>

namespace Drivers {
    namespace Hyperv {
        namespace Wmi {
            namespace Classes {
                namespace V2 {
                    typedef struct _Msvm_ComputerSystem_Data {
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
                        XML_TYPE_STR PrimaryOwnerName;
                        XML_TYPE_STR PrimaryOwnerContact;
                        XML_TYPE_DYN_ARRAY Roles;
                        XML_TYPE_STR NameFormat;
                        XML_TYPE_DYN_ARRAY OtherIdentifyingInfo;
                        XML_TYPE_DYN_ARRAY IdentifyingDescriptions;
                        XML_TYPE_DYN_ARRAY Dedicated;
                        XML_TYPE_DYN_ARRAY OtherDedicatedDescriptions;
                        XML_TYPE_UINT16 ResetCapability;
                        XML_TYPE_DYN_ARRAY PowerManagementCapabilities;
                        XML_TYPE_UINT64 OnTimeInMilliseconds;
                        XML_TYPE_STR TimeOfLastConfigurationChange;
                        XML_TYPE_UINT32 ProcessID;
                        XML_TYPE_DYN_ARRAY AssignedNumaNodeList;

                    } Msvm_ComputerSystem_Data;
                    
                    SER_DECLARE_TYPE(Msvm_ComputerSystem_Data);
                    
                    typedef struct _Msvm_ComputerSystem {
                        XmlSerializerInfo *serializerInfo;
                        Msvm_ComputerSystem_Data *data;
                    } Msvm_ComputerSystem;
                    
                    #define V2_MSVM_COMPUTERSYSTEM_RESOURCE_URI \
                        "http://schemas.microsoft.com/wbem/wsman/1/wmi/root/virtualization/v2/Msvm_ComputerSystem"
                    
                    #define V2_MSVM_COMPUTERSYSTEM_CLASSNAME \
                        "Msvm_ComputerSystem"
                    
                    #define V2_MSVM_COMPUTERSYSTEM_WQL_SELECT \
                        "select * from Msvm_ComputerSystem "
                    
                    class MsvmComputerSystemMeta : public AbstractWmiObject
                    {
                    public:
                      MsvmComputerSystemMeta();
                    };
                }
            }
        }
    }
}

#endif /* V2_MSVM_COMPUTERSYSTEM_H */

