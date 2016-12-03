#include "VirtualMachine.h"

namespace Objects {

VirtualMachine::VirtualMachine(VirtualMachineData data): data_(data) {}

std::string VirtualMachine::getState()
{
    std::string stateString;
    switch(this->data_.state) {
    case VirtualMachineState::RUNNING:
        stateString = "Running";
        break;
    case VirtualMachineState::POWERED_OFF:
        stateString = "Powered Off";
        break;
    case VirtualMachineState::POWERED_ON:
        stateString = "Powered On";
        break;
    case VirtualMachineState::PAUSED:
        stateString = "Paused";
        break;
    case VirtualMachineState::UNKNOWN:
        stateString = "Unknown";
        break;
    }
    return stateString;
}

std::string VirtualMachine::toString()
{
    std::stringstream s;
    s << this->data_.name << " " << this->data_.id << " " << this->getState();
    return s.str();
}
}