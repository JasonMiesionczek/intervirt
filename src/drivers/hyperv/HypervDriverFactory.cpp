#include <drivers/hyperv/HypervDriverFactory.h>

HypervDriverFactory::HypervDriverFactory()
{

}

IDriverPtr HypervDriverFactory::connect(ConnectionPtr conn)
{
    auto common = new HypervCommon(conn);
    auto result = common->enumerate<v1::Win32OperatingSystem>();
    auto data = result[0].getRawData();
    
    return std::make_shared<HypervDriverLegacy>(conn);
}