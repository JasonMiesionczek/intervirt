#ifndef DRIVERFACTORY_H
#define DRIVERFACTORY_H

#include <drivers/IDriverFactory.h>
#include <iostream>
#include <string>
#include <memory>
#include <map>

namespace Drivers {
  class DriverFactory
  {
  public:
    DriverFactory();
    bool registerDriver(std::string name, std::shared_ptr<IDriverFactory> factory);
    std::shared_ptr<IDriverFactory> create(std::string driver);

  private:
    std::map<std::string, std::shared_ptr<IDriverFactory>> factoryMap;
  };

}

#endif /* DRIVERFACTORY_H */
