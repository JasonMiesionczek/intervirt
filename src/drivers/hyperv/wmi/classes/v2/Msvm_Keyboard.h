
#ifndef V2_MSVM_KEYBOARD_H
#define V2_MSVM_KEYBOARD_H

#include <common/util.h>
#include <drivers/hyperv/wmi/AbstractWmiObject.h>

namespace Drivers {
    namespace Hyperv {
        namespace Wmi {
            namespace Classes {
                namespace V2 {
                    typedef struct _Msvm_Keyboard_Data {
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
                        XML_TYPE_BOOL IsLocked;
                        XML_TYPE_STR Layout;
                        XML_TYPE_UINT16 NumberOfFunctionKeys;
                        XML_TYPE_UINT16 Password;
                        XML_TYPE_BOOL UnicodeSupported;

                    } Msvm_Keyboard_Data;
                    
                    SER_DECLARE_TYPE(Msvm_Keyboard_Data);
                    
                    typedef struct _Msvm_Keyboard {
                        XmlSerializerInfo *serializerInfo;
                        Msvm_Keyboard_Data *data;
                    } Msvm_Keyboard;
                    
                    #define V2_MSVM_KEYBOARD_RESOURCE_URI \
                        "http://schemas.microsoft.com/wbem/wsman/1/wmi/root/virtualization/v2/Msvm_Keyboard"
                    
                    #define V2_MSVM_KEYBOARD_CLASSNAME \
                        "Msvm_Keyboard"
                    
                    #define V2_MSVM_KEYBOARD_WQL_SELECT \
                        "select * from Msvm_Keyboard "
                    
                    class MsvmKeyboardMeta : public AbstractWmiObject
                    {
                    public:
                      MsvmKeyboardMeta();
                    };
                }
            }
        }
    }
}

#endif /* V2_MSVM_KEYBOARD_H */

