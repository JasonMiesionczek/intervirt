#include "server.h"
#include <jsonrpccpp/server/connectors/httpserver.h>
#include <iostream>
#include <memory>

using namespace jsonrpc;

int main()
{
    std::cout << "test" << std::endl;

    auto server = std::make_shared<HttpServer>(8383);
    
}