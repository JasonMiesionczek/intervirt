#ifndef SHELLCONTEXT_H
#define SHELLCONTEXT_H

#include <common/util.h>
#include <shell/rpcclient.h>
#include <shell/colors.h>
#include <objects/HypervisorConnection.h>

class ShellContext
{
public:
  ShellContext(Connection::ConnectionPtr conn = nullptr);
  void setConnId(std::string id) { this->connId_ = id; }
  void setClient(SHRDPTR(RpcClient) client) { this->client_ = client; }
  std::string getConnId() { return this->connId_; }
  SHRDPTR(RpcClient) getClient() { return this->client_; }
  std::string getPrompt();

private:
  Connection::ConnectionPtr conn_;
  std::string connId_;
  SHRDPTR(RpcClient) client_;
};

#endif /* SHELLCONTEXT_H */
