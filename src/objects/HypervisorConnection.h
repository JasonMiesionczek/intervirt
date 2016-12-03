#ifndef HYPERVISORCONNECTION_H
#define HYPERVISORCONNECTION_H

#include <common/util.h>
#include <libxml/uri.h>

namespace Connection {
  class HypervisorConnection
  {
  public:
    HypervisorConnection(std::string uri, std::string password = std::string());
    std::string getProtocol();
    std::string getUsername();
    std::string getPassword();
    std::string getHost();
    void setPassword(std::string pw) { this->password_ = pw; }

  private:
    std::string username_;
    std::string password_;
    std::string host_;
    std::string protocol_;
    int port;
  };

  using ConnectionPtr = SHRDPTR(HypervisorConnection);
} // namespace Connection

#endif /* HYPERVISORCONNECTION_H */
