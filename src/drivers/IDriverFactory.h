#ifndef IDRIVERFACTORY_H
#define IDRIVERFACTORY_H

#include <common/util.h>
#include <drivers/IDriver.h>
#include <objects/HypervisorConnection.h>

namespace Drivers {
class IDriverFactory {
public:
  IDriverFactory() {}
  virtual ~IDriverFactory();
  IDriverFactory(IDriverFactory &&) = default;
  IDriverFactory &operator=(IDriverFactory &&) = default;
  IDriverFactory(const IDriverFactory &) = default;
  IDriverFactory &operator=(const IDriverFactory &) = default;
  virtual IDriverPtr create(Connection::ConnectionPtr conn) = 0;
};

using IDriverFactoryPtr = std::shared_ptr<IDriverFactory>;
}
#endif /* IDRIVERFACTORY_H */
