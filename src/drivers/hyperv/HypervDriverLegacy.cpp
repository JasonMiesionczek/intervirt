#include "HypervDriverLegacy.h"

namespace Drivers {
namespace Hyperv {

HypervDriverLegacy::HypervDriverLegacy(Connection::ConnectionPtr conn, SHRDPTR(Wmi::WmiHelper) helper) :
    IDriver(conn), helper_(helper) {}

std::string HypervDriverLegacy::hostGetVersion()
{
    auto os = this->helper_->Enumerate<Wmi::Classes::Common::Win32_OperatingSystem, Wmi::Classes::Common::Win32OperatingSystem>();
    return os[0]->data->Version;
}
}
}