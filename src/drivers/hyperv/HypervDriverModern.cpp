#include "HypervDriverModern.h"

namespace Drivers {
namespace Hyperv {

HypervDriverModern::HypervDriverModern(Connection::ConnectionPtr conn, SHRDPTR(Wmi::WmiHelper) helper) :
    HypervDriverCommon(conn, helper), helper_(helper) {}

std::string HypervDriverModern::hostGetVersion()
{
    auto os = this->helper_->Enumerate<Wmi::Classes::Common::Win32_OperatingSystem, Wmi::Classes::Common::Win32OperatingSystem>();
    return os[0]->data->Version;
}

std::vector<SHRDPTR(Objects::VirtualMachine)> HypervDriverModern::getVirtualMachines()
{
    std::vector<SHRDPTR(Objects::VirtualMachine)> vms;

    auto result = this->helper_->Enumerate<Wmi::Classes::V2::Msvm_ComputerSystem, Wmi::Classes::V2::MsvmComputerSystem>();

    for (auto vm : result)
    {
        Objects::VirtualMachineData data = {
            .name = vm->data->ElementName,
            .id = vm->data->Name};
        auto newVm = MKSHRD(Objects::VirtualMachine, data);
        vms.push_back(newVm);
    }

    this->helper_->FreeResults(result);

    return vms;
}
}
}