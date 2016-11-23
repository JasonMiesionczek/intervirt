#ifndef DRIVERMANAGER_H
#define DRIVERMANAGER_H

#include <drivers/IDriverFactory.h>
#include <iostream>
#include <string>
#include <memory>
#include <map>

namespace Drivers {
  class DriverManager
  {
  public:
    DriverManager();
    bool registerDriver(std::string name, IDriverFactoryPtr factory);
    IDriverFactoryPtr get(std::string driver);

  private:
    std::map<std::string, IDriverFactoryPtr> factoryMap;
  };

}

#endif /* DRIVERMANAGER_H */
