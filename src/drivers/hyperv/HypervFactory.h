#ifndef HYPERVFACTORY_H
#define HYPERVFACTORY_H

#include <common/util.h>
#include <drivers/IDriver.h>
#include <drivers/IDriverFactory.h>
#include <drivers/hyperv/HypervDriverLegacy.h>
#include <drivers/hyperv/HypervDriverModern.h>
#include <drivers/hyperv/wmi/WmiHelper.h>
#include <drivers/hyperv/wmi/classes/common/Win32_OperatingSystem.h>
#include <objects/HypervisorConnection.h>

using namespace Drivers::Hyperv::Wmi::Classes::Common;

namespace Drivers {
    namespace Hyperv {
        class HypervFactory : public IDriverFactory {
        public:
            HypervFactory() {}

            virtual ~HypervFactory();

            IDriverPtr create(Connection::ConnectionPtr conn);
        };
    }
}

#endif /* HYPERVFACTORY_H */
