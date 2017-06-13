#ifndef SHELLCONTEXT_H
#define SHELLCONTEXT_H

#include <common/util.h>
#include <objects/HypervisorConnection.h>
#include <shell/colors.h>
#include <shell/rpcclient.h>

class ShellContext {
public:
    ShellContext(Connection::ConnectionPtr conn = nullptr);

    void setConnId(std::string id) { this->connId_ = id; }

    void setClient(SHRDPTR(RpcClient) client) { this->client_ = client; }

    void setConnection(Connection::ConnectionPtr conn) { this->conn_ = conn; }

    std::string getConnId() { return this->connId_; }

    SHRDPTR(RpcClient) getClient() { return this->client_; }

    Connection::ConnectionPtr getConnection() { return this->conn_; }

    std::string getPrompt();

private:
    Connection::ConnectionPtr conn_;
    std::string connId_;
    SHRDPTR(RpcClient) client_;
};

#endif /* SHELLCONTEXT_H */
