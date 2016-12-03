#ifndef SHELLCONTEXT_H
#define SHELLCONTEXT_H

#include <common/util.h>
#include <objects/HypervisorConnection.h>

class ShellContext
{
public:
  ShellContext(Connection::ConnectionPtr conn = nullptr);
  void setConnId(std::string id) { this->connId_ = id; }
private:
  Connection::ConnectionPtr conn_;
  std::string connId_;
};

#endif /* SHELLCONTEXT_H */
