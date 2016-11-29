#ifndef IDRIVER_H
#define IDRIVER_H

#include <common/util.h>
#include <objects/HypervisorConnection.h>
#include <objects/VirtualMachine.h>

namespace Drivers {
    class IDriver
    {
    public:
      IDriver(Connection::ConnectionPtr conn);
      virtual std::string hostGetVersion() = 0;
      virtual std::vector<SHRDPTR(Objects::VirtualMachine)> getVirtualMachines() = 0;

    private:
      Connection::ConnectionPtr conn_;
    };
    
    using IDriverPtr = SHRDPTR(IDriver);
}

#endif /* IDRIVER_H */
