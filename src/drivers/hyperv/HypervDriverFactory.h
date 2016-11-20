#ifndef HYPERVDRIVERFACTORY_H
#define HYPERVDRIVERFACTORY_H

#include <drivers/IDriverFactory.h>
#include <drivers/IDriver.h>
#include <drivers/hyperv/HypervDriverLegacy.h>
#include <string>
#include <memory>

class HypervDriverFactory : public IDriverFactory
{
public:
  HypervDriverFactory();
  std::shared_ptr<IDriver> connect(std::string host, std::string username, std::string password);
};

#endif /* HYPERVDRIVERFACTORY_H */
