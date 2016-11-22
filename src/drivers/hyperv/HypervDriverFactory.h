#ifndef HYPERVDRIVERFACTORY_H
#define HYPERVDRIVERFACTORY_H

#include <drivers/IDriverFactory.h>
#include <drivers/IDriver.h>
#include <drivers/hyperv/HypervDriverLegacy.h>
#include <objects/HypervisorConnection.h>
#include <drivers/hyperv/HypervCommon.h>
#include <string>
#include <memory>

using namespace Connection;

class HypervDriverFactory : public IDriverFactory
{
public:
  HypervDriverFactory();
  IDriverPtr connect(ConnectionPtr conn);
};

#endif /* HYPERVDRIVERFACTORY_H */
