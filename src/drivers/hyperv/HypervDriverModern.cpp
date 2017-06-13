#include "HypervDriverModern.h"

namespace Drivers {
    namespace Hyperv {

        HypervDriverModern::HypervDriverModern(Connection::ConnectionPtr conn,
                                               SHRDPTR(Wmi::WmiHelper) helper)
                : HypervDriverCommon(conn, helper), helper_(helper) {}

        Objects::VirtualMachineState msvmStateToVmStateV2(XML_TYPE_UINT16 state) {
            switch (state) {
                case static_cast<int>(V2_Msvm_EnabledState::UNKNOWN):
                    return Objects::VirtualMachineState::UNKNOWN;
                case static_cast<int>(V2_Msvm_EnabledState::ENABLED):
                    return Objects::VirtualMachineState::RUNNING;
                case static_cast<int>(V2_Msvm_EnabledState::DISABLED):
                    return Objects::VirtualMachineState::POWERED_OFF;
                case static_cast<int>(V2_Msvm_EnabledState::STARTING):
                case static_cast<int>(V2_Msvm_EnabledState::QUIESCE):
                    return Objects::VirtualMachineState::RUNNING;
                case static_cast<int>(V2_Msvm_EnabledState::SHUTTING_DOWN):
                case static_cast<int>(V2_Msvm_EnabledState::NOT_APPLICABLE):
                    return Objects::VirtualMachineState::POWERED_OFF;
            }
            return Objects::VirtualMachineState::UNKNOWN;
        }

        std::string HypervDriverModern::hostGetVersion() {
            auto os =
                    this->helper_->Enumerate<Wmi::Classes::Common::Win32_OperatingSystem,
                            Wmi::Classes::Common::Win32OperatingSystemMeta>();
            return os[0]->data->Version;
        }

        std::vector<SHRDPTR(Objects::VirtualMachine) >
        HypervDriverModern::getVirtualMachines() {
            std::vector<SHRDPTR(Objects::VirtualMachine) > vms;

            auto result =
                    this->helper_->Enumerate<Wmi::Classes::V2::Msvm_ComputerSystem,
                            Wmi::Classes::V2::MsvmComputerSystemMeta>();

            for (auto vm : result) {
                Objects::VirtualMachineData data = {
                        .name = vm->data->ElementName,
                        .id = vm->data->Name,
                        .state = msvmStateToVmStateV2(vm->data->EnabledState)};
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
