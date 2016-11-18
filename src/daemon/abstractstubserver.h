/**
 * This file is generated by jsonrpcstub, DO NOT CHANGE IT MANUALLY!
 */

#ifndef JSONRPC_CPP_STUB_ABSTRACTSTUBSERVER_H_
#define JSONRPC_CPP_STUB_ABSTRACTSTUBSERVER_H_

#include <jsonrpccpp/server.h>

class AbstractStubServer : public jsonrpc::AbstractServer<AbstractStubServer>
{
    public:
        AbstractStubServer(jsonrpc::AbstractServerConnector &conn, jsonrpc::serverVersion_t type = jsonrpc::JSONRPC_SERVER_V2) : jsonrpc::AbstractServer<AbstractStubServer>(conn, type)
        {
            this->bindAndAddMethod(jsonrpc::Procedure("getVersion", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_STRING,  NULL), &AbstractStubServer::getVersionI);
        }

        inline virtual void getVersionI(const Json::Value &request, Json::Value &response)
        {
            (void)request;
            response = this->getVersion();
        }
        virtual std::string getVersion() = 0;
};

#endif //JSONRPC_CPP_STUB_ABSTRACTSTUBSERVER_H_
