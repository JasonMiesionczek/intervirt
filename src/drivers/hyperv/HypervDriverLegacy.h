#ifndef HYPERVDRIVERLEGACY_H
#define HYPERVDRIVERLEGACY_H

#include <common/util.h>
#include <drivers/IDriver.h>
#include <objects/HypervisorConnection.h>
#include <drivers/hyperv/wmi/WmiHelper.h>
#include <drivers/hyperv/wmi/classes/common/Win32_OperatingSystem.h>

namespace Drivers {
namespace Hyperv {

class HypervDriverLegacy : public IDriver
{
public:
  HypervDriverLegacy(Connection::ConnectionPtr conn, SHRDPTR(Wmi::WmiHelper) helper);
  std::string hostGetVersion();

private:
  SHRDPTR(Wmi::WmiHelper) helper_;
};
}
}

#endif /* HYPERVDRIVERLEGACY_H */
