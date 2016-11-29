#ifndef HYPERVDRIVERCOMMON_H
#define HYPERVDRIVERCOMMON_H

#include <common/util.h>
#include <drivers/hyperv/wmi/WmiHelper.h>
#include <drivers/hyperv/wmi/classes/common/common.h>
#include <drivers/IDriver.h>
#include <objects/HypervisorConnection.h>

namespace Drivers {
namespace Hyperv {

enum class V1_Msvm_EnabledState : int {
    UNKNOWN = 0,          /* inactive */
    ENABLED = 2,          /*   active */
    DISABLED = 3,         /* inactive */
    PAUSED = 32768,       /*   active */
    SUSPENDED = 32769,    /* inactive */
    STARTING = 32770,     /*   active */
    SNAPSHOTTING = 32771, /*   active */
    SAVING = 32773,       /*   active */
    STOPPING = 32774,     /*   active */
    PAUSING = 32776,      /*   active */
    RESUMING = 32777      /*   active */
};

class HypervDriverCommon : public IDriver
{
public:
  HypervDriverCommon(Connection::ConnectionPtr conn, SHRDPTR(Wmi::WmiHelper) helper);
  std::string hostGetVersion();
private:
  SHRDPTR(Wmi::WmiHelper) helper_;
};
}
}

#endif /* HYPERVDRIVERCOMMON_H */
