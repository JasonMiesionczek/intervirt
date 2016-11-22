#ifndef HYPERVISORCONNECTION_H
#define HYPERVISORCONNECTION_H

#include <string>
#include <memory>
#include <libxml/uri.h>

namespace Connection
{

class HypervisorConnection
{
public:
  HypervisorConnection(std::string uri, std::string password);
  std::string getProtocol();
  std::string getUsername();
  std::string getPassword();
  std::string getHost();

private:
  std::string username;
  std::string password;
  std::string host;
  std::string protocol;
  int port;
};

using ConnectionPtr = std::shared_ptr<HypervisorConnection>;

} // namespace Connection

#endif /* HYPERVISORCONNECTION_H */
