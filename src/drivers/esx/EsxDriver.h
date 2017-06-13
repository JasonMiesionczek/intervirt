#ifndef ESXDRIVER_H
#define ESXDRIVER_H

#include <common/util.h>
#include <drivers/IDriver.h>
#include <drivers/esx/api/EsxApi.hpp>
#include <objects/HypervisorConnection.h>
#include <objects/VirtualMachine.h>

namespace Drivers {
    namespace Esx {

        class EsxDriver : public IDriver {
        public:
            EsxDriver(Connection::ConnectionPtr conn);

            virtual std::string hostGetVersion();

            virtual std::vector<SHRDPTR(Objects::VirtualMachine) > getVirtualMachines();

        private:
            SHRDPTR(EsxApi) api_;
        };
    }
}

#endif /* ESXDRIVER_H */
