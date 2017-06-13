#include "HypervDriverCommon.h"

namespace Drivers {
    namespace Hyperv {
        HypervDriverCommon::HypervDriverCommon(Connection::ConnectionPtr conn,
                                               SHRDPTR(Wmi::WmiHelper) helper)
                : IDriver(conn), helper_(helper) {}

        std::string HypervDriverCommon::hostGetVersion() {
            auto os =
                    this->helper_->Enumerate<Wmi::Classes::Common::Win32_OperatingSystem,
                            Wmi::Classes::Common::Win32OperatingSystemMeta>();
            return os[0]->data->Version;
        }
    }
}
