#include "HypervFactory.h"

namespace Drivers {
namespace Hyperv {

HypervFactory::~HypervFactory() {}

IDriverPtr HypervFactory::create(Connection::ConnectionPtr conn) {
  auto helper = MKSHRD(Wmi::WmiHelper, conn);
  auto objects =
      helper->Enumerate<Win32_OperatingSystem, Win32OperatingSystem>();
  auto version = objects[0]->data->Version;
  IDriverPtr driver = nullptr;
  char *hypervVersion = (char *)calloc(4, sizeof(char));
  strncpy(hypervVersion, version, 3);
  if (strcmp(hypervVersion, "6.1") == 0) {
    driver = MKSHRD(HypervDriverLegacy, conn, helper);
  } else {
    driver = MKSHRD(HypervDriverModern, conn, helper);
  }

  return driver;
}
}
}
