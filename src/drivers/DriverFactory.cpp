#include "DriverFactory.h"

namespace Drivers {
DriverFactory::DriverFactory()
{

}

bool DriverFactory::registerDriver(std::string name, std::shared_ptr<IDriverFactory> factory)
{
    factoryMap[name] = factory;
    return true;
}
}