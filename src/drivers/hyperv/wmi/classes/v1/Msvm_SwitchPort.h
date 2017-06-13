
#ifndef V1_MSVM_SWITCHPORT_H
#define V1_MSVM_SWITCHPORT_H

#include <common/util.h>
#include <drivers/hyperv/wmi/AbstractWmiObject.h>

namespace Drivers {
    namespace Hyperv {
        namespace Wmi {
            namespace Classes {
                namespace V1 {
                    typedef struct _Msvm_SwitchPort_Data {
                        XML_TYPE_STR Caption;
                        XML_TYPE_STR ElementName;
                        XML_TYPE_STR InstallDate;
                        XML_TYPE_DYN_ARRAY StatusDescriptions;
                        XML_TYPE_STR Status;
                        XML_TYPE_UINT16 HealthState;
                        XML_TYPE_STR OtherEnabledState;
                        XML_TYPE_UINT16 RequestedState;
                        XML_TYPE_UINT16 EnabledDefault;
                        XML_TYPE_STR SystemCreationClassName;
                        XML_TYPE_STR SystemName;
                        XML_TYPE_STR CreationClassName;
                        XML_TYPE_STR Description;
                        XML_TYPE_DYN_ARRAY OperationalStatus;
                        XML_TYPE_UINT16 EnabledState;
                        XML_TYPE_STR TimeOfLastStateChange;
                        XML_TYPE_STR Name;
                        XML_TYPE_STR NameFormat;
                        XML_TYPE_UINT16 ProtocolType;
                        XML_TYPE_UINT16 ProtocolIFType;
                        XML_TYPE_STR OtherTypeDescription;
                        XML_TYPE_BOOL BroadcastResetSupported;
                        XML_TYPE_UINT16 PortNumber;
                        XML_TYPE_STR ScopeOfResidence;
                        XML_TYPE_UINT32 VMQOffloadWeight;
                        XML_TYPE_UINT32 ChimneyOffloadWeight;
                        XML_TYPE_UINT32 VMQOffloadUsage;
                        XML_TYPE_UINT32 ChimneyOffloadUsage;
                        XML_TYPE_UINT32 VMQOffloadLimit;
                        XML_TYPE_UINT32 ChimneyOffloadLimit;
                        XML_TYPE_BOOL AllowMacSpoofing;

                    } Msvm_SwitchPort_Data;
                    
                    SER_DECLARE_TYPE(Msvm_SwitchPort_Data);
                    
                    typedef struct _Msvm_SwitchPort {
                        XmlSerializerInfo *serializerInfo;
                        Msvm_SwitchPort_Data *data;
                    } Msvm_SwitchPort;
                    
                    #define V1_MSVM_SWITCHPORT_RESOURCE_URI \
                        "http://schemas.microsoft.com/wbem/wsman/1/wmi/root/virtualization/Msvm_SwitchPort"
                    
                    #define V1_MSVM_SWITCHPORT_CLASSNAME \
                        "Msvm_SwitchPort"
                    
                    #define V1_MSVM_SWITCHPORT_WQL_SELECT \
                        "select * from Msvm_SwitchPort "
                    
                    class MsvmSwitchPortMeta : public AbstractWmiObject
                    {
                    public:
                      MsvmSwitchPortMeta();
                    };
                }
            }
        }
    }
}

#endif /* V1_MSVM_SWITCHPORT_H */

