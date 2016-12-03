#include "RpcServer.h"

RpcServer::RpcServer(AbstractServerConnector &connector, SHRDPTR(Drivers::DriverManager) manager) :
    AbstractStubServer(connector), manager_(manager)
    {

    }

std::string genConnectionID(std::string uri, std::string password)
{
    unsigned char result[MD5_DIGEST_LENGTH];
    MD5((unsigned char*)uri.c_str(), uri.size(), result);

    std::ostringstream sout;
    sout<<std::hex<<std::setfill('0');
    for(long long c: result)
    {
        sout<<std::setw(2)<<(long long)c;
    }
    return sout.str();
}

std::string RpcServer::connect(const std::string &password, const std::string &uri)
{
    auto conn = MKSHRD(Connection::HypervisorConnection, uri, password);
    auto factory = this->manager_->get(conn->getProtocol());
    auto driver = factory->create(conn);
    auto id = genConnectionID(uri, password);
    this->connectionMap_[id] = driver;
    return id;
}

std::string RpcServer::hostGetVersion(const std::string& connID)
{
    auto driver = this->connectionMap_[connID];
    return driver->hostGetVersion();
}

Json::Value RpcServer::getAllVirtualMachines(const std::string& connID)
{
    auto driver = this->connectionMap_[connID];
    Json::Value result;
    auto vms = driver->getVirtualMachines();
    for (auto&& vm : vms) {
        Json::Value singleVm;
        singleVm["name"] = vm->getData().name;
        singleVm["id"] = vm->getData().id;
        singleVm["state"] = vm->getState();
        result.append(singleVm);
    }
    return result;
}