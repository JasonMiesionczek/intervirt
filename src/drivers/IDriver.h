#ifndef IDRIVER_H
#define IDRIVER_H

#include <common/util.h>
#include <objects/HypervisorConnection.h>

namespace Drivers {
    class IDriver
    {
    public:
      IDriver(Connection::ConnectionPtr conn);
      virtual std::string hostGetVersion() = 0;

    private:
      Connection::ConnectionPtr conn_;
    };
    
    using IDriverPtr = SHRDPTR(IDriver);
}

#endif /* IDRIVER_H */
