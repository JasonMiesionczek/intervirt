#ifndef IDRIVER_H
#define IDRIVER_H

#include <common/util.h>
#include <objects/HypervisorConnection.h>
#include <objects/VirtualMachine.h>

namespace Drivers {
class IDriver {
public:
  IDriver(Connection::ConnectionPtr conn);
  virtual std::string hostGetVersion() {
    throw std::runtime_error("Function not implemented");
  }
  virtual std::vector<SHRDPTR(Objects::VirtualMachine)> getVirtualMachines() {
    throw std::runtime_error("Function not implemented");
  }

private:
  Connection::ConnectionPtr conn_;
};

using IDriverPtr = SHRDPTR(IDriver);
}

#endif /* IDRIVER_H */
