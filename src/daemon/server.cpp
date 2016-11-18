#include "server.h"

RpcServer::RpcServer(AbstractServerConnector &connector) :
    AbstractStubServer(connector)
    {

    }

std::string RpcServer::getVersion()
{
    return "0.1.0";
}