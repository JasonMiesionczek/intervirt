
#include "Win32_ComputerSystemProduct.h"

namespace Drivers {
    namespace Hyperv {
        namespace Wmi {
            namespace Classes {
                namespace Common {

                    SER_START_ITEMS(Win32_ComputerSystemProduct_Data)
                        SER_NS_STR(COMMON_WIN32_COMPUTERSYSTEMPRODUCT_RESOURCE_URI, "Caption", 1),
                        SER_NS_STR(COMMON_WIN32_COMPUTERSYSTEMPRODUCT_RESOURCE_URI, "Description", 1),
                        SER_NS_STR(COMMON_WIN32_COMPUTERSYSTEMPRODUCT_RESOURCE_URI, "IdentifyingNumber", 1),
                        SER_NS_STR(COMMON_WIN32_COMPUTERSYSTEMPRODUCT_RESOURCE_URI, "Name", 1),
                        SER_NS_STR(COMMON_WIN32_COMPUTERSYSTEMPRODUCT_RESOURCE_URI, "SKUNumber", 1),
                        SER_NS_STR(COMMON_WIN32_COMPUTERSYSTEMPRODUCT_RESOURCE_URI, "UUID", 1),
                        SER_NS_STR(COMMON_WIN32_COMPUTERSYSTEMPRODUCT_RESOURCE_URI, "Vendor", 1),
                        SER_NS_STR(COMMON_WIN32_COMPUTERSYSTEMPRODUCT_RESOURCE_URI, "Version", 1),

                    SER_END_ITEMS(Win32_ComputerSystemProduct_Data);
                    
                    Win32ComputerSystemProductMeta::Win32ComputerSystemProductMeta()
                            :AbstractWmiObject(
                                COMMON_WIN32_COMPUTERSYSTEMPRODUCT_WQL_SELECT,
                                COMMON_WIN32_COMPUTERSYSTEMPRODUCT_CLASSNAME,
                                "http://schemas.microsoft.com/wbem/wsman/1/wmi/root/cimv2/*",
                                COMMON_WIN32_COMPUTERSYSTEMPRODUCT_RESOURCE_URI,
                                Win32_ComputerSystemProduct_Data_TypeInfo
                            ) {}

                }
            }
        }
    }
}
