#include <drivers/hyperv/HypervDriverFactory.h>

HypervDriverFactory::HypervDriverFactory()
{

}

std::shared_ptr<IDriver> HypervDriverFactory::connect(std::string host, std::string username, std::string password)
{
    return std::make_shared<HypervDriverLegacy>();
}