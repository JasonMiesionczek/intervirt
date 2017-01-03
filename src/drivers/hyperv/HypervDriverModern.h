#ifndef HYPERVDRIVERMODERN_H
#define HYPERVDRIVERMODERN_H

#include <common/util.h>
#include <drivers/IDriver.h>
#include <drivers/hyperv/HypervDriverCommon.h>
#include <drivers/hyperv/wmi/WmiHelper.h>
#include <drivers/hyperv/wmi/classes/common/common.h>
#include <drivers/hyperv/wmi/classes/v2/v2.h>
#include <objects/HypervisorConnection.h>
#include <objects/VirtualMachine.h>

namespace Drivers {
namespace Hyperv {

class HypervDriverModern : public HypervDriverCommon {
public:
  HypervDriverModern(Connection::ConnectionPtr conn,
                     SHRDPTR(Wmi::WmiHelper) helper);
  virtual std::string hostGetVersion();
  virtual std::vector<SHRDPTR(Objects::VirtualMachine)> getVirtualMachines();

private:
  SHRDPTR(Wmi::WmiHelper) helper_;
};
}
}

#endif /* HYPERVDRIVERMODERN_H */
