#include <objects/HypervisorConnection.h>

namespace Connection
{

HypervisorConnection::HypervisorConnection(std::string uri, std::string password)
    : password(password)
{
    auto uriParsed = xmlParseURI(uri.c_str());
    this->protocol = uriParsed->scheme;
    this->username = uriParsed->user;
    this->host = uriParsed->server;
    this->port = uriParsed->port;
}

std::string HypervisorConnection::getProtocol()
{
    return this->protocol;
}

std::string HypervisorConnection::getUsername()
{
    return this->username;
}

std::string HypervisorConnection::getPassword()
{
    return this->password;
}

std::string HypervisorConnection::getHost()
{
    return this->host;
}

} // namespace Connection