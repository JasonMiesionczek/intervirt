#ifndef HYPERVDRIVERLEGACY_H
#define HYPERVDRIVERLEGACY_H

#include <common/util.h>
#include <drivers/IDriver.h>
#include <drivers/hyperv/HypervDriverCommon.h>
#include <drivers/hyperv/wmi/WmiHelper.h>
#include <drivers/hyperv/wmi/classes/common/common.h>
#include <drivers/hyperv/wmi/classes/v1/v1.h>
#include <objects/HypervisorConnection.h>
#include <objects/VirtualMachine.h>

namespace Drivers {
namespace Hyperv {

class HypervDriverLegacy : public HypervDriverCommon {
public:
  HypervDriverLegacy(Connection::ConnectionPtr conn,
                     SHRDPTR(Wmi::WmiHelper) helper);
  std::vector<SHRDPTR(Objects::VirtualMachine)> getVirtualMachines();

private:
  SHRDPTR(Wmi::WmiHelper) helper_;
};
}
}

#endif /* HYPERVDRIVERLEGACY_H */
