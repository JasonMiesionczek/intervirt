#include <common/util.h>
#include <curl/curl.h>
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

#define XML_TAG(name, type)                                                    \
  "<" name "xmlns=\"urn:vim25\" xsi:type=\"xsd:" type "\">"

class ApiObjectValue {
public:
    ApiObjectValue(std::string value)
            : value_(value) {
    }

    ~ApiObjectValue() = default;

    ApiObjectValue(const ApiObjectValue &other) = default;

    ApiObjectValue(ApiObjectValue &&other) = default;

    ApiObjectValue &operator=(const ApiObjectValue &other) = default;

    ApiObjectValue &operator=(ApiObjectValue &&other) = default;

    std::string asString() { return this->value_; }

private:
    std::string value_;
};

class ApiObject {
public:
    ApiObject(std::string name)
            : name_(name), value_(nullptr) {
    }

    ~ApiObject() = default;

    ApiObject(const ApiObject &other) = default;

    ApiObject(ApiObject &&other) = default;

    ApiObject &operator=(const ApiObject &other) = default;

    ApiObject &operator=(ApiObject &&other) = default;

    void addChild(std::string name, std::shared_ptr<ApiObject> obj) {
        this->children_[name].push_back(obj);
    }

    void addAttr(std::string name, std::string value) {
        this->attrs_[name] = std::make_shared<ApiObjectValue>(value);
    }

    void setValue(std::string value) {
        this->value_ = std::make_shared<ApiObjectValue>(value);
    }

    std::vector<ApiObject> operator>>(const std::string name) {
        std::vector<ApiObject> result;
        for (auto &o : this->children_[name]) {
            result.push_back(*o);
        }
        return result;
    }

    ApiObjectValue operator[](const std::string attr) {
        return *this->attrs_[attr];
    }

    ApiObjectValue operator()() { return *this->value_; }

private:
    std::string name_;
    std::map<std::string, std::shared_ptr<ApiObjectValue>> attrs_;
    std::shared_ptr<ApiObjectValue> value_;
    std::map<std::string, std::vector<std::shared_ptr<ApiObject>>> children_;
};

SHRDPTR(ApiObject)
parseResponse(xmlpp::Node *node, std::shared_ptr<ApiObject> object = nullptr) {
    const xmlpp::ContentNode *nodeContent =
            dynamic_cast<const xmlpp::ContentNode *>(node);
    const xmlpp::TextNode *nodeText = dynamic_cast<const xmlpp::TextNode *>(node);
    const xmlpp::CommentNode *nodeComment =
            dynamic_cast<const xmlpp::CommentNode *>(node);
    const xmlpp::Element *nodeElement = dynamic_cast<const xmlpp::Element *>(node);

    auto obj = std::make_shared<ApiObject>(node->get_name());

    if (node->get_name() == "text" && object != nullptr) {
        object->setValue(nodeContent->get_content());
        return object;
    }

    if (object != nullptr) {
        object->addChild(node->get_name(), obj);
    }

    if (nodeElement) {
        for (auto &attr : nodeElement->get_attributes()) {
            obj->addAttr(attr->get_name(), attr->get_value());
        }
    }

    if (nodeContent) {
        obj->setValue(nodeContent->get_content());
    } else if (nodeText) {
        obj->setValue(nodeText->get_content());
    } else if (nodeComment) {
        obj->setValue(nodeComment->get_content());
    } else {
        auto children = node->get_children();
        for (auto &child : children) {
            parseResponse(child, obj);
        }
    }

    return obj;
}

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
std::string propertyCollector;

std::string
buildRequest(std::string method, std::string morefType, RequestParams params,
             std::string rawParams = std::string()) {
    std::stringstream ss;
    ss << ESX_VI__SOAP__REQUEST_HEADER;
    ss << "<" << method << " xmlns=\"urn:vim25\">";
    ss << "<_this xmlns=\"urn:vim25\" xsi:type=\"ManagedObjectReference\" type=\""
       << morefType << "\">";
    if (morefType == "PropertyCollector") {
        ss << propertyCollector << "</_this>";
    } else {
        ss << morefType << "</_this>";
    }
    for (auto &param : params) {
        ss << param.toString();
    }
    ss << rawParams;
    ss << "</" << method << ">";
    ss << ESX_VI__SOAP__REQUEST_FOOTER;
    return ss.str();
}

std::string
buildCustomRequest(std::string method, RequestParam morefType,
                   RequestParams params, std::string rawParams = std::string()) {
    std::stringstream ss;
    ss << ESX_VI__SOAP__REQUEST_HEADER;
    ss << "<" << method << " xmlns=\"urn:vim25\">";
    ss << "<_this xmlns=\"urn:vim25\" xsi:type=\"ManagedObjectReference\" type=\""
       << morefType.type << "\">";
    ss << morefType.name << "</_this>";
    for (auto &param : params) {
        ss << param.toString();
    }
    ss << rawParams;
    ss << "</" << method << ">";
    ss << ESX_VI__SOAP__REQUEST_FOOTER;
    return ss.str();
}

ApiObject
ExecuteRequest(CURL *client, std::string method, std::string morefType,
               RequestParams params = {}, std::string rawParams = std::string(),
               std::string rawRequest = std::string()) {
    auto request = rawRequest;
    if (request.size() == 0) {
        request = buildRequest(method, morefType, params, rawParams);
    }
    std::string content;
    // std::cout << request << "\n";
    curl_easy_setopt(client, CURLOPT_POSTFIELDS, request.c_str());
    curl_easy_setopt(client, CURLOPT_POSTFIELDSIZE, strlen(request.c_str()));
    curl_easy_setopt(client, CURLOPT_WRITEDATA, &content);

    CURLcode errorCode;
    long responseCode;
    errorCode = curl_easy_perform(client);
    if (errorCode != CURLE_OK) {
        std::cerr << curl_easy_strerror(errorCode) << std::endl;
    }
    errorCode = curl_easy_getinfo(client, CURLINFO_RESPONSE_CODE, &responseCode);
    if (errorCode != CURLE_OK) {
        std::cerr << curl_easy_strerror(errorCode) << std::endl;
    }
    xmlpp::DomParser parser;
    parser.set_substitute_entities();
    std::stringstream ss;
    ss << content;
    // std::cout << content << "\n";
    try {
        parser.parse_stream(ss);
        if (parser) {
            xmlpp::Element *node = parser.get_document()->get_root_node();
            node->set_namespace_declaration(
                    "http://schemas.xmlsoap.org/soap/envelope/", "soapenv");
            node->set_namespace_declaration("urn:vim25", "vim");

            auto n = static_cast<xmlpp::Node *>(node);
            std::map<Glib::ustring, Glib::ustring> nsmap;
            nsmap["soapenv"] = "http://schemas.xmlsoap.org/soap/envelope/";
            nsmap["vim"] = "urn:vim25";

            auto foundError =
                    n->find("/soapenv:Envelope/soapenv:Body/soapenv:Fault", nsmap);
            if (!foundError.empty()) {
                std::cerr << "Got SOAP fault"
                          << "\n";
                auto faultObject = parseResponse(foundError[0]);
                std::cout << (*faultObject >> "faultstring")[0]().asString() << "\n";
                return *faultObject;
            } else {
                std::stringstream responseXpath;
                responseXpath << "/soapenv:Envelope/soapenv:Body/vim:" << method
                              << "Response";
                auto set = n->find(responseXpath.str(), nsmap);
                auto response = set[0];
                auto returnVal = response->find("./vim:returnval", nsmap);
                if (returnVal.size() > 1) {
                    ApiObject resultHolder("resultHolder");
                    for (auto &result : returnVal) {
                        resultHolder.addChild("result", parseResponse(result));
                    }
                    return resultHolder;
                } else {
                    auto object = parseResponse(returnVal[0]);
                    return *object;
                }
            }
        }
    } catch (xmlpp::internal_error e) {
        std::cerr << e.what() << std::endl;
    }
    ApiObject errorObject("error");
    return errorObject;
}

ApiObject
RetrieveProperties(CURL *client, std::string type, RequestParam object,
                   RequestParams propSet, RequestParams objSet) {
    std::stringstream params;

    params << "<specSet xmlns=\"urn:vim25\" xsi:type=\"PropertyFilterSpec\">";
    params << "<propSet xmlns=\"urn:vim25\" xsi:type=\"PropertySpec\">";
    params << "<type xmlns=\"urn:vim25\" xsi:type=\"xsd:string\">";
    params << type;
    params << "</type>";
    for (auto &pset : propSet) {
        params << pset.toPropSet();
    }
    params << "</propSet>";
    params << "<objectSet xmlns=\"urn:vim25\" xsi:type=\"ObjectSpec\">";
    params
            << "<obj xmlns=\"urn:vim25\" xsi:type=\"ManagedObjectReference\" type=\""
            << object.name << "\">";
    params << object.value << "</obj>";

    params << "<skip xmlns=\"urn:vim25\" xsi:type=\"xsd:boolean\">false</skip>";
    params << "<selectSet xmlns=\"urn:vim25\" xsi:type=\"TraversalSpec\">";
    for (auto &oset : objSet) {
        params << oset.toString();
    }
    params << "</selectSet>";
    params << "</objectSet>";
    params << "</specSet>";

    return ExecuteRequest(client, "RetrieveProperties", "PropertyCollector", {},
                          params.str());
}

ApiObject
Login(CURL *handle, std::string username, std::string password,
      std::string sessionManager) {
    auto request = buildCustomRequest(
            "Login", {.name = sessionManager, .type = "SessionManager"},
            {{.name = "userName", .value = username, .type = "string"},
             {.name = "password", .value = password, .type = "string"}});

    auto req = ExecuteRequest(handle, "Login", "SessionManager", {}, {}, request);
    return req;
}

static size_t
WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    ((std::string *) userp)->append((char *) contents, size * nmemb);
    return size * nmemb;
}

int
main() {
    curl_global_init(CURL_GLOBAL_DEFAULT);
    CURL *handle;
    struct curl_slist *headers = NULL;
    char error[CURL_ERROR_SIZE];

    auto url = "https://10.0.21.:443/sdk";

    handle = curl_easy_init();
    headers = curl_slist_append(headers, "Content-Type: text/xml; charset=UTF-8");
    headers = curl_slist_append(headers, "Expect:");
    curl_easy_setopt(handle, CURLOPT_USERAGENT, "intervirt-esx");
    curl_easy_setopt(handle, CURLOPT_NOSIGNAL, 1);
    curl_easy_setopt(handle, CURLOPT_HEADER, 0);
    curl_easy_setopt(handle, CURLOPT_FOLLOWLOCATION, 0);
    curl_easy_setopt(handle, CURLOPT_SSL_VERIFYPEER, 0);
    curl_easy_setopt(handle, CURLOPT_SSL_VERIFYHOST, 0);
    curl_easy_setopt(handle, CURLOPT_COOKIEFILE, "");
    curl_easy_setopt(handle, CURLOPT_HTTPHEADER, headers);
    // curl_easy_setopt(handle, CURLOPT_READFUNCTION, esxVI_CURL_ReadString);
    curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(handle, CURLOPT_ERRORBUFFER, error);
    curl_easy_setopt(handle, CURLOPT_URL, url);
    curl_easy_setopt(handle, CURLOPT_RANGE, NULL);
    curl_easy_setopt(handle, CURLOPT_UPLOAD, 0);
    curl_easy_setopt(handle, CURLOPT_VERBOSE, 0);

    auto serviceContent =
            ExecuteRequest(handle, "RetrieveServiceContent", "ServiceInstance");
    std::cout << ((serviceContent >> "about")[0] >> "fullName")[0]().asString()
              << "\n";
    auto rootFolder = (serviceContent >> "rootFolder")[0]().asString();
    auto sessionManager = (serviceContent >> "sessionManager")[0]().asString();
    propertyCollector = (serviceContent >> "propertyCollector")[0]().asString();
    std::cout << rootFolder << "\n";
    std::string hostFolder;

    auto req = Login(handle, "root", "S0uthernDarkn3$$", sessionManager);
    std::cout << (req >> "key")[0]().asString() << "\n";
    std::cout << "getting root folder"
              << "\n";
    auto rootFolderReq = RetrieveProperties(
            handle, "Folder", {.name = "Folder", .value = rootFolder},
            {{.name = "name", .type = "string"}},
            {{.name = "name", .type = "string", .value = "folderToChildEntity"},
             {.name = "type", .type = "string", .value = "Folder"},
             {.name = "path", .type = "string", .value = "childEntity"},
             {.name = "skip", .type = "boolean", .value = "false"}});
    std::cout << "getting datacenters"
              << "\n";
    auto dcVal = (((rootFolderReq >> "propSet")[0]) >> "val")[0]().asString();
    std::cout << dcVal << "\n";
    if (dcVal == "Datacenters") {
        // get the datacenter
        std::cout << "found datacenter"
                  << "\n";
        auto datacenter = RetrieveProperties(
                handle, "Datacenter", {.name = "Folder", .value = rootFolder},
                {{.name = "name", .type = "string"},
                 {.name = "hostFolder", .type = "string"},
                 {.name = "vmFolder", .type = "string"}},
                {{.name = "name", .type = "string", .value = "folderToChildEntity"},
                 {.name = "type", .type = "string", .value = "Folder"},
                 {.name = "path", .type = "string", .value = "childEntity"},
                 {.name = "skip", .type = "boolean", .value = "false"}});
        hostFolder = (((datacenter >> "propSet")[0]) >> "val")[0]().asString();
    } else {
        hostFolder = "ha-folder-host";
    }

    std::cout << "host folder:" << hostFolder << "\n";
    auto resource = RetrieveProperties(
            handle, "ComputeResource", {.name = "Folder", .value = hostFolder},
            {{.name = "name", .type = "string"},
             {.name = "host", .type = "string"},
             {.name = "resourcePool", .type = "string"}},
            {{.name = "name", .type = "string", .value = "folderToChildEntity"},
             {.name = "type", .type = "string", .value = "Folder"},
             {.name = "path", .type = "string", .value = "childEntity"},
             {.name = "skip", .type = "boolean", .value = "false"}});

    std::string hostName;
    std::vector<std::string> hostNames;
    auto domain = (resource >> "obj")[0]().asString();
    std::cout << domain << "\n";
    auto propSets = (resource >> "propSet");
    for (auto &pset : propSets) {
        auto name = (pset >> "name")[0]().asString();
        std::cout << name << "\n";
        if (name == "host") {
            auto vals = (pset >> "val");
            for (auto &val : vals) {
                auto moref = (val >> "ManagedObjectReference");
                // std::cout << (val >> "ManagedObjectReference")[0]().asString() <<
                // "\n";
                hostName = moref[0]().asString();
                for (auto &host : moref) {
                    std::cout << host().asString() << "\n";
                    hostNames.push_back(host().asString());
                }
            }
        }
    }

    for (auto &host : hostNames) {
        auto vmRequest = RetrieveProperties(
                handle, "VirtualMachine", {.name = "HostSystem", .value = host},
                {{.name = "configStatus", .type = "string"},
                 {.name = "name", .type = "string"},
                 {.name = "config.uuid", .type = "string"},
                 {.name = "runtime.powerState", .type = "string"}},
                {{.name = "name", .type = "string", .value = "hostSystemToVm"},
                 {.name = "type", .type = "string", .value = "HostSystem"},
                 {.name = "path", .type = "string", .value = "vm"},
                 {.name = "skip", .type = "boolean", .value = "false"}});

        auto vms = (vmRequest >> "result");
        for (auto &vm : vms) {
            std::cout << (vm >> "obj")[0]().asString() << "\n";
            auto props = (vm >> "propSet");
            for (auto &prop : props) {
                std::cout << "      " << (prop >> "name")[0]().asString() << ": "
                          << (prop >> "val")[0]().asString() << "\n";
            }
        }
    }

    curl_easy_cleanup(handle);
    curl_slist_free_all(headers);
    curl_global_cleanup();
}
