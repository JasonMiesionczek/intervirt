#include "EsxDriver.h"

namespace Drivers {
namespace Esx {

EsxDriver::EsxDriver(Connection::ConnectionPtr conn) : IDriver(conn) {}

std::string EsxDriver::hostGetVersion()
{
    return "0.0.0";
}

std::vector<SHRDPTR(Objects::VirtualMachine)> EsxDriver::getVirtualMachines()
{
    std::vector<SHRDPTR(Objects::VirtualMachine)> vms;
    return vms;
}
}
}