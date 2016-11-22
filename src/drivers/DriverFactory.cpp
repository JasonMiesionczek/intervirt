#include "DriverFactory.h"

namespace Drivers
{

DriverFactory::DriverFactory()
{

}

bool DriverFactory::registerDriver(std::string name, std::shared_ptr<IDriverFactory> factory)
{
    factoryMap[name] = factory;
    return true;
}

std::shared_ptr<IDriverFactory> DriverFactory::create(std::string driver)
{
    auto driverFactory = this->factoryMap.find(driver);
    if (driverFactory == this->factoryMap.end()) {
        return nullptr;
    } else {
        return driverFactory->second;
    }
}

}  // namespace Drivers