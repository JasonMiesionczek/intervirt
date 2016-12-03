#ifndef RPCSERVER_H
#define RPCSERVER_H

#include "abstractstubserver.h"
#include <jsonrpccpp/server/connectors/httpserver.h>
#include <drivers/IDriver.h>
#include <drivers/DriverManager.h>
#include <objects/HypervisorConnection.h>
#include <openssl/md5.h>

using namespace jsonrpc;
using namespace std;

class RpcServer : public AbstractStubServer
{
    public:
        RpcServer(AbstractServerConnector &connector, SHRDPTR(Drivers::DriverManager) manager);

        virtual std::string connect(const std::string &password, const std::string &uri);
        virtual std::string hostGetVersion(const std::string& connID);
        virtual Json::Value getAllVirtualMachines(const std::string &connID);

      private:
        std::map<std::string, SHRDPTR(Drivers::IDriver)> connectionMap_;
        SHRDPTR(Drivers::DriverManager) manager_;
};

#endif /* SERVER_H */
