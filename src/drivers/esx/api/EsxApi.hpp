//
//  EsxApi.hpp
//  intervirt
//
//  Created by Jason Miesionczek on 12/14/2016.
//
//

#ifndef EsxApi_hpp
#define EsxApi_hpp

#include <common/util.h>
#include <curl/curl.h>
#include <drivers/esx/api/ApiObject.hpp>
#include <libxml++/libxml++.h>

#define ESX_VI__SOAP__REQUEST_HEADER                                           \
  "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"                               \
  "<soapenv:Envelope\n"                                                        \
  " xmlns:soapenv=\"http://schemas.xmlsoap.org/soap/envelope/\"\n"             \
  " xmlns:soapenc=\"http://schemas.xmlsoap.org/soap/encoding/\"\n"             \
  " xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"\n"                 \
  " xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\">\n"                         \
  "<soapenv:Body>\n"

#define ESX_VI__SOAP__REQUEST_FOOTER                                           \
  "</soapenv:Body>\n"                                                          \
  "</soapenv:Envelope>"

typedef struct _requestParam {
  std::string value;
  std::string name;
  std::string type;
  std::string toString() {
    std::stringstream ss;
    ss << "<" << name << " xmlns=\"urn:vim25\" xsi:type=\"xsd:" << type << "\">"
       << value << "</" << name << ">";
    return ss.str();
  }
  std::string toPropSet() {
    std::stringstream ss;
    ss << "<pathSet xmlns=\"urn:vim25\" xsi:type=\"xsd:" << type << "\">"
       << name << "</pathSet>";
    return ss.str();
  }
} RequestParam;

using RequestParams = std::vector<RequestParam>;
using namespace Drivers::Esx::Api;

class EsxApi {
public:
  EsxApi(std::string url);
  ~EsxApi();
  EsxApi(const EsxApi &other) = default;
  EsxApi(EsxApi &&other) = default;
  EsxApi &operator=(const EsxApi &other) = default;
  EsxApi &operator=(EsxApi &&other) = default;

  std::vector<std::string> getHostnames() { return this->hostNames; }

  std::string buildCustomRequest(std::string method, RequestParam morefType,
                                 RequestParams params,
                                 std::string rawParams = std::string());
  ApiObject RetrieveProperties(std::string type, RequestParam object,
                               RequestParams propSet, RequestParams objSet);
  ApiObject ExecuteRequest(std::string method, std::string morefType,
                           RequestParams params = {},
                           std::string rawParams = std::string(),
                           std::string rawRequest = std::string());
  ApiObject Login(std::string username, std::string password);

protected:
  std::string buildRequest(std::string method, std::string morefType,
                           RequestParams params,
                           std::string rawParams = std::string());
  ApiObject getServiceContext();
  std::string getVersion() { return this->version; }
  void determineHostFolder();
  void determineHosts();

private:
  CURL *client;
  struct curl_slist *headers;
  std::string propertyCollector;
  std::string sessionManager;
  std::string rootFolder;
  std::string hostFolder;
  std::string version;
  std::vector<std::string> hostNames;
};

#endif /* EsxApi_hpp */
