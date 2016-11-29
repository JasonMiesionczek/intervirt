#ifndef ESXDRIVER_H
#define ESXDRIVER_H

#include <common/util.h>
#include <drivers/IDriver.h>
#include <objects/HypervisorConnection.h>
#include <objects/VirtualMachine.h>

namespace Drivers {
namespace Esx {

class EsxDriver : public IDriver
{
public:
  EsxDriver(Connection::ConnectionPtr conn);
  std::string hostGetVersion();
  std::vector<SHRDPTR(Objects::VirtualMachine)> getVirtualMachines();
};
}
}



#endif /* ESXDRIVER_H */
