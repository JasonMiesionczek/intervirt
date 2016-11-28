
#include "Msvm_Keyboard.h"

namespace Drivers {
namespace Hyperv {
namespace Wmi {
namespace Classes {
namespace V2 {


SER_START_ITEMS(Msvm_Keyboard_Data)
    SER_NS_STR(MSVM_KEYBOARD_RESOURCE_URI, "InstanceID", 1),
    SER_NS_STR(MSVM_KEYBOARD_RESOURCE_URI, "Caption", 1),
    SER_NS_STR(MSVM_KEYBOARD_RESOURCE_URI, "Description", 1),
    SER_NS_STR(MSVM_KEYBOARD_RESOURCE_URI, "ElementName", 1),
    SER_NS_STR(MSVM_KEYBOARD_RESOURCE_URI, "InstallDate", 1),
    SER_NS_STR(MSVM_KEYBOARD_RESOURCE_URI, "Name", 1),
    SER_NS_DYN_ARRAY(MSVM_KEYBOARD_RESOURCE_URI, "OperationalStatus", 0, 0, uint16),
    SER_NS_DYN_ARRAY(MSVM_KEYBOARD_RESOURCE_URI, "StatusDescriptions", 0, 0, string),
    SER_NS_STR(MSVM_KEYBOARD_RESOURCE_URI, "Status", 1),
    SER_NS_UINT16(MSVM_KEYBOARD_RESOURCE_URI, "HealthState", 1),
    SER_NS_UINT16(MSVM_KEYBOARD_RESOURCE_URI, "CommunicationStatus", 1),
    SER_NS_UINT16(MSVM_KEYBOARD_RESOURCE_URI, "DetailedStatus", 1),
    SER_NS_UINT16(MSVM_KEYBOARD_RESOURCE_URI, "OperatingStatus", 1),
    SER_NS_UINT16(MSVM_KEYBOARD_RESOURCE_URI, "PrimaryStatus", 1),
    SER_NS_UINT16(MSVM_KEYBOARD_RESOURCE_URI, "EnabledState", 1),
    SER_NS_STR(MSVM_KEYBOARD_RESOURCE_URI, "OtherEnabledState", 1),
    SER_NS_UINT16(MSVM_KEYBOARD_RESOURCE_URI, "RequestedState", 1),
    SER_NS_UINT16(MSVM_KEYBOARD_RESOURCE_URI, "EnabledDefault", 1),
    SER_NS_STR(MSVM_KEYBOARD_RESOURCE_URI, "TimeOfLastStateChange", 1),
    SER_NS_DYN_ARRAY(MSVM_KEYBOARD_RESOURCE_URI, "AvailableRequestedStates", 0, 0, uint16),
    SER_NS_UINT16(MSVM_KEYBOARD_RESOURCE_URI, "TransitioningToState", 1),
    SER_NS_STR(MSVM_KEYBOARD_RESOURCE_URI, "SystemCreationClassName", 1),
    SER_NS_STR(MSVM_KEYBOARD_RESOURCE_URI, "SystemName", 1),
    SER_NS_STR(MSVM_KEYBOARD_RESOURCE_URI, "CreationClassName", 1),
    SER_NS_STR(MSVM_KEYBOARD_RESOURCE_URI, "DeviceID", 1),
    SER_NS_BOOL(MSVM_KEYBOARD_RESOURCE_URI, "PowerManagementSupported", 1),
    SER_NS_DYN_ARRAY(MSVM_KEYBOARD_RESOURCE_URI, "PowerManagementCapabilities", 0, 0, uint16),
    SER_NS_UINT16(MSVM_KEYBOARD_RESOURCE_URI, "Availability", 1),
    SER_NS_UINT16(MSVM_KEYBOARD_RESOURCE_URI, "StatusInfo", 1),
    SER_NS_UINT32(MSVM_KEYBOARD_RESOURCE_URI, "LastErrorCode", 1),
    SER_NS_STR(MSVM_KEYBOARD_RESOURCE_URI, "ErrorDescription", 1),
    SER_NS_BOOL(MSVM_KEYBOARD_RESOURCE_URI, "ErrorCleared", 1),
    SER_NS_DYN_ARRAY(MSVM_KEYBOARD_RESOURCE_URI, "OtherIdentifyingInfo", 0, 0, string),
    SER_NS_UINT64(MSVM_KEYBOARD_RESOURCE_URI, "PowerOnHours", 1),
    SER_NS_UINT64(MSVM_KEYBOARD_RESOURCE_URI, "TotalPowerOnHours", 1),
    SER_NS_DYN_ARRAY(MSVM_KEYBOARD_RESOURCE_URI, "IdentifyingDescriptions", 0, 0, string),
    SER_NS_DYN_ARRAY(MSVM_KEYBOARD_RESOURCE_URI, "AdditionalAvailability", 0, 0, uint16),
    SER_NS_UINT64(MSVM_KEYBOARD_RESOURCE_URI, "MaxQuiesceTime", 1),
    SER_NS_BOOL(MSVM_KEYBOARD_RESOURCE_URI, "IsLocked", 1),
    SER_NS_STR(MSVM_KEYBOARD_RESOURCE_URI, "Layout", 1),
    SER_NS_UINT16(MSVM_KEYBOARD_RESOURCE_URI, "NumberOfFunctionKeys", 1),
    SER_NS_UINT16(MSVM_KEYBOARD_RESOURCE_URI, "Password", 1),
    SER_NS_BOOL(MSVM_KEYBOARD_RESOURCE_URI, "UnicodeSupported", 1),

SER_END_ITEMS(Msvm_Keyboard_Data);

MsvmKeyboard::MsvmKeyboard()
        :AbstractWmiObject(
            MSVM_KEYBOARD_WQL_SELECT,
            MSVM_KEYBOARD_CLASSNAME,
            "",
            MSVM_KEYBOARD_RESOURCE_URI,
            Msvm_Keyboard_Data_TypeInfo
        ) {}

}
}
}
}
}
