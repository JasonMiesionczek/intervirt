#include "RpcServer.h"

RpcServer::RpcServer(AbstractServerConnector &connector,
                     SHRDPTR(Drivers::DriverManager) manager)
    : AbstractStubServer(connector), manager_(manager) {}

void log(std::string message, LogSeverity severity) {
  auto console = spdlog::get("console");
  auto file = spdlog::get("logger");

  switch (severity) {
  case LogSeverity::DEBUG:
    console->debug(message);
    file->debug(message);
    break;
  case LogSeverity::INFO:
    console->info(message);
    file->info(message);
    break;
  case LogSeverity::WARN:
    console->warn(message);
    file->warn(message);
    break;
  case LogSeverity::CRITICAL:
    console->critical(message);
    file->critical(message);
    break;
  case LogSeverity::ERROR:
    console->error(message);
    file->error(message);
    break;
  }
}

std::string genConnectionID(std::string uri) {
  unsigned char result[MD5_DIGEST_LENGTH];
  MD5((unsigned char *)uri.c_str(), uri.size(), result);

  std::ostringstream sout;
  sout << std::hex << std::setfill('0');
  for (long long c : result) {
    sout << std::setw(2) << (long long)c;
  }
  return sout.str();
}

std::string RpcServer::connect(const std::string &password,
                               const std::string &uri) {
  auto id = genConnectionID(uri);
  auto foundDriver = this->connectionMap_.find(id);
  if (foundDriver == this->connectionMap_.end()) {
    auto conn = MKSHRD(Connection::HypervisorConnection, uri, password);
    auto factory = this->manager_->get(conn->getProtocol());
    auto driver = factory->create(conn);

    this->connectionMap_[id] = driver;
    std::stringstream ss;
    ss << "New connection to " << conn->getHost() << " using driver "
       << conn->getProtocol() << " with id " << id;
    log(ss.str(), LogSeverity::INFO);
  } else {
    std::stringstream ss;
    ss << "Using existing connection with id: " << id;
    log(ss.str(), LogSeverity::INFO);
  }

  return id;
}

std::string RpcServer::hostGetVersion(const std::string &connID) {
  auto driver = this->connectionMap_[connID];
  std::stringstream ss;

  auto version = driver->hostGetVersion();
  ss << "hostGetVersion called for connId: " << connID
     << ", value returned: " << version;
  log(ss.str(), LogSeverity::INFO);
  return version;
}

Json::Value RpcServer::getAllVirtualMachines(const std::string &connID) {
  auto driver = this->connectionMap_[connID];
  Json::Value result;
  auto vms = driver->getVirtualMachines();
  for (auto &&vm : vms) {
    Json::Value singleVm;
    singleVm["name"] = vm->getData().name;
    singleVm["id"] = vm->getData().id;
    singleVm["state"] = vm->getState();
    result.append(singleVm);
  }
  return result;
}
