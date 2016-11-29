#ifndef ESXFACTORY_H
#define ESXFACTORY_H

#include <common/util.h>
#include <drivers/IDriverFactory.h>
#include <drivers/IDriver.h>
#include <objects/HypervisorConnection.h>
#include <drivers/esx/EsxDriver.h>

namespace Drivers {
namespace Esx {

class EsxFactory : public IDriverFactory
{
public:
  
  EsxFactory() {}
  virtual ~EsxFactory();
  IDriverPtr create(Connection::ConnectionPtr conn);
};
}
}

#endif /* ESXFACTORY_H */
