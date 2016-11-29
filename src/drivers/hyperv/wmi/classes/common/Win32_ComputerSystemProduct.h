
#ifndef COMMON_WIN32_COMPUTERSYSTEMPRODUCT_H
#define COMMON_WIN32_COMPUTERSYSTEMPRODUCT_H

#include <common/util.h>
#include <drivers/hyperv/wmi/AbstractWmiObject.h>

namespace Drivers {
namespace Hyperv {
namespace Wmi {
namespace Classes {
namespace Common {
typedef struct _Win32_ComputerSystemProduct_Data {
    XML_TYPE_STR Caption;
    XML_TYPE_STR Description;
    XML_TYPE_STR IdentifyingNumber;
    XML_TYPE_STR Name;
    XML_TYPE_STR SKUNumber;
    XML_TYPE_STR UUID;
    XML_TYPE_STR Vendor;
    XML_TYPE_STR Version;

} Win32_ComputerSystemProduct_Data;
SER_DECLARE_TYPE(Win32_ComputerSystemProduct_Data);
typedef struct _Win32_ComputerSystemProduct {
    XmlSerializerInfo *serializerInfo;
    Win32_ComputerSystemProduct_Data *data;
} Win32_ComputerSystemProduct;

#define COMMON_WIN32_COMPUTERSYSTEMPRODUCT_RESOURCE_URI \
    "http://schemas.microsoft.com/wbem/wsman/1/wmi/root/cimv2/Win32_ComputerSystemProduct"

#define COMMON_WIN32_COMPUTERSYSTEMPRODUCT_CLASSNAME \
    "Win32_ComputerSystemProduct"

#define COMMON_WIN32_COMPUTERSYSTEMPRODUCT_WQL_SELECT \
    "select * from Win32_ComputerSystemProduct "

class Win32ComputerSystemProduct : public AbstractWmiObject
{
public:
  Win32ComputerSystemProduct();
};
}
}
}
}
}
#endif /* COMMON_WIN32_COMPUTERSYSTEMPRODUCT_H */

