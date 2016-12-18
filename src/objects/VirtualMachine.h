#ifndef VIRTUALMACHINE_H
#define VIRTUALMACHINE_H

#include <common/util.h>

namespace Objects {
enum class VirtualMachineState {
  POWERED_OFF,
  POWERED_ON,
  PAUSED,
  RUNNING,
  UNKNOWN
};

typedef struct _VirtualMachine {
  std::string name;
  std::string id;
  VirtualMachineState state;
} VirtualMachineData;

class VirtualMachine {
public:
  VirtualMachine(VirtualMachineData data);
  std::string toString();

  VirtualMachineData getData() { return this->data_; }
  std::string getState();

private:
  VirtualMachineData data_;
};
}

#endif /* VIRTUALMACHINE_H */
