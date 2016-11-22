#ifndef HYPERVDRIVERLEGACY_H
#define HYPERVDRIVERLEGACY_H

#include <drivers/IDriver.h>
#include <drivers/hyperv/HypervCommon.h>

class HypervDriverLegacy : public IDriver, public HypervCommon
{
public:    
    HypervDriverLegacy(Connection::ConnectionPtr conn);
};

#endif /* HYPERVDRIVERLEGACY_H */
