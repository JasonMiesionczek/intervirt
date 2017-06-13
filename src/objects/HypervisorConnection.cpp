#include <objects/HypervisorConnection.h>

namespace Connection {
    HypervisorConnection::HypervisorConnection(std::string uri,
                                               std::string password)
            : password_(password) {
        auto uriParsed = xmlParseURI(uri.c_str());
        this->protocol_ = uriParsed->scheme;
        this->username_ = uriParsed->user;
        this->host_ = uriParsed->server;
        this->port = uriParsed->port;
    }

    std::string HypervisorConnection::getProtocol() { return this->protocol_; }

    std::string HypervisorConnection::getUsername() { return this->username_; }

    std::string HypervisorConnection::getPassword() { return this->password_; }

    std::string HypervisorConnection::getHost() { return this->host_; }
} // namespace Connection
