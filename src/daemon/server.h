#ifndef SERVER_H
#define SERVER_H

#include "abstractstubserver.h"
#include <jsonrpccpp/server/connectors/httpserver.h>

using namespace jsonrpc;
using namespace std;

class RpcServer : public AbstractStubServer
{
    public:
        RpcServer(AbstractServerConnector &connector);

        virtual std::string getVersion();
};

#endif /* SERVER_H */
