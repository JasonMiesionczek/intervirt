#ifndef IDRIVERFACTORY_H
#define IDRIVERFACTORY_H

#include <drivers/IDriver.h>
#include <objects/HypervisorConnection.h>
#include <iostream>
#include <string>
#include <memory>

class IDriverFactory
{
public:
  IDriverFactory() {}
  virtual ~IDriverFactory();
  IDriverFactory(IDriverFactory &&) = default;
  IDriverFactory &operator=(IDriverFactory &&) = default;
  IDriverFactory(const IDriverFactory &) = default;
  IDriverFactory &operator=(const IDriverFactory &) = default;
  virtual std::shared_ptr<IDriver> connect(std::shared_ptr<Connection::HypervisorConnection> conn) = 0;
};

#endif /* IDRIVERFACTORY_H */
