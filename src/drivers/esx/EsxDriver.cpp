#include "EsxDriver.h"

namespace Drivers {
namespace Esx {

EsxDriver::EsxDriver(Connection::ConnectionPtr conn)
    : IDriver(conn), api_(MKSHRD(EsxApi, conn->getHost())) {
  this->api_->Login(conn->getUsername(), conn->getPassword());
}

std::string EsxDriver::hostGetVersion() { return this->api_->getVersion(); }

std::vector<SHRDPTR(Objects::VirtualMachine)> EsxDriver::getVirtualMachines() {
  std::vector<SHRDPTR(Objects::VirtualMachine)> vms;

  for (auto &host : this->api_->getHostnames()) {
    auto vmRequest = this->api_->RetrieveProperties(
        "VirtualMachine", {.name = "HostSystem", .value = host},
        {{.name = "configStatus", .type = "string"},
         {.name = "name", .type = "string"},
         {.name = "config.uuid", .type = "string"},
         {.name = "runtime.powerState", .type = "string"}},
        {{.name = "name", .type = "string", .value = "hostSystemToVm"},
         {.name = "type", .type = "string", .value = "HostSystem"},
         {.name = "path", .type = "string", .value = "vm"},
         {.name = "skip", .type = "boolean", .value = "false"}});

    auto vmResult = (vmRequest >> "result");
    for (auto &vm : vmResult) {
      Objects::VirtualMachineData newVm;
      std::cout << (vm >> "obj")[0]().asString() << "\n";
      auto props = (vm >> "propSet");
      for (auto &prop : props) {
        auto propName = (prop >> "name")[0]().asString();
        auto propValue = (prop >> "val")[0]().asString();
        if (propName == "config.uuid") {
          newVm.id = propValue;
        }
        if (propName == "name") {
          newVm.name = propValue;
        }
        if (propName == "runtime.powerState") {
          if (propValue == "poweredOn") {
            newVm.state = Objects::VirtualMachineState::POWERED_ON;
          } else if (propValue == "poweredOff") {
            newVm.state = Objects::VirtualMachineState::POWERED_OFF;
          } else {
            newVm.state = Objects::VirtualMachineState::UNKNOWN;
          }
        }
      }
      vms.push_back(MKSHRD(Objects::VirtualMachine, newVm));
    }
  }
  std::sort(vms.begin(), vms.end(),
            [](const SHRDPTR(Objects::VirtualMachine) vm1,
               const SHRDPTR(Objects::VirtualMachine) vm2) {
              return (vm1->getData().name < vm2->getData().name);
            });
  return vms;
}
} // Esx namespace
} // Drivers namespace
