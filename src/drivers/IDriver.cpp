#include "IDriver.h"

namespace Drivers {
    IDriver::IDriver(Connection::ConnectionPtr conn)
        : conn_(conn)
        {
            
        }
}