#include "DriverManager.h"

namespace Drivers {
DriverManager::DriverManager() {}

bool DriverManager::registerDriver(std::string name,
                                   IDriverFactoryPtr factory) {
  factoryMap[name] = factory;
  return true;
}

IDriverFactoryPtr DriverManager::get(std::string driver) {
  auto driverFactory = this->factoryMap.find(driver);
  if (driverFactory == this->factoryMap.end()) {
    return nullptr;
  } else {
    return driverFactory->second;
  }
}
} // namespace Drivers
