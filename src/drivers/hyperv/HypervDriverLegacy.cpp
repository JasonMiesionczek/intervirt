#include "HypervDriverLegacy.h"

namespace Drivers {
    namespace Hyperv {

        HypervDriverLegacy::HypervDriverLegacy(Connection::ConnectionPtr conn,
                                               SHRDPTR(Wmi::WmiHelper) helper)
                : HypervDriverCommon(conn, helper), helper_(helper) {}

        Objects::VirtualMachineState msvmStateToVmState(XML_TYPE_UINT16 state) {
            switch (state) {
                case static_cast<int>(V1_Msvm_EnabledState::UNKNOWN):
                    return Objects::VirtualMachineState::UNKNOWN;
                case static_cast<int>(V1_Msvm_EnabledState::ENABLED):
                    return Objects::VirtualMachineState::RUNNING;
                case static_cast<int>(V1_Msvm_EnabledState::PAUSED):
                    return Objects::VirtualMachineState::PAUSED;
                case static_cast<int>(V1_Msvm_EnabledState::STARTING):
                case static_cast<int>(V1_Msvm_EnabledState::SNAPSHOTTING):
                case static_cast<int>(V1_Msvm_EnabledState::SAVING):
                    return Objects::VirtualMachineState::RUNNING;
                case static_cast<int>(V1_Msvm_EnabledState::STOPPING):
                case static_cast<int>(V1_Msvm_EnabledState::PAUSING):
                    return Objects::VirtualMachineState::POWERED_OFF;
                case static_cast<int>(V1_Msvm_EnabledState::RESUMING):
                    return Objects::VirtualMachineState::RUNNING;
                case static_cast<int>(V1_Msvm_EnabledState::DISABLED):
                    return Objects::VirtualMachineState::POWERED_OFF;
            }
            return Objects::VirtualMachineState::UNKNOWN;
        }

        std::vector<SHRDPTR(Objects::VirtualMachine) >
        HypervDriverLegacy::getVirtualMachines() {
            std::vector<SHRDPTR(Objects::VirtualMachine) > vms;

            auto result =
                    this->helper_->Enumerate<Wmi::Classes::V1::Msvm_ComputerSystem,
                            Wmi::Classes::V1::MsvmComputerSystemMeta>();

            for (auto vm : result) {
                Objects::VirtualMachineData data = {
                        .name = vm->data->ElementName,
                        .id = vm->data->Name,
                        .state = msvmStateToVmState(vm->data->EnabledState)};
                auto newVm = MKSHRD(Objects::VirtualMachine, data);
                vms.push_back(newVm);
            }

            this->helper_->FreeResults(result);
            std::sort(vms.begin(), vms.end(),
                      [](const SHRDPTR(Objects::VirtualMachine) vm1,
                         const SHRDPTR(Objects::VirtualMachine) vm2) {
                          return (vm1->getData().name < vm2->getData().name);
                      });
            return vms;
        }
    }
}
