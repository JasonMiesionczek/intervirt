//
//  EsxApi.cpp
//  intervirt
//
//  Created by Jason Miesionczek on 12/14/2016.
//
//

#include "EsxApi.hpp"

static size_t
WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    ((std::string *) userp)->append((char *) contents, size * nmemb);
    return size * nmemb;
}

EsxApi::EsxApi(std::string host) {
    char error[CURL_ERROR_SIZE];
    std::stringstream url;
    url << "https://" << host << ":443/sdk";
    this->client = curl_easy_init();
    this->headers = NULL;
    this->headers =
            curl_slist_append(this->headers, "Content-Type: text/xml; charset=UTF-8");
    this->headers = curl_slist_append(this->headers, "Expect:");
    curl_easy_setopt(this->client, CURLOPT_USERAGENT, "intervirt-esx");
    curl_easy_setopt(this->client, CURLOPT_NOSIGNAL, 1);
    curl_easy_setopt(this->client, CURLOPT_HEADER, 0);
    curl_easy_setopt(this->client, CURLOPT_FOLLOWLOCATION, 0);
    curl_easy_setopt(this->client, CURLOPT_SSL_VERIFYPEER, 0);
    curl_easy_setopt(this->client, CURLOPT_SSL_VERIFYHOST, 0);
    curl_easy_setopt(this->client, CURLOPT_COOKIEFILE, "");
    curl_easy_setopt(this->client, CURLOPT_HTTPHEADER, this->headers);
    curl_easy_setopt(this->client, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(this->client, CURLOPT_ERRORBUFFER, error);
    curl_easy_setopt(this->client, CURLOPT_URL, url.str().c_str());
    curl_easy_setopt(this->client, CURLOPT_RANGE, NULL);
    curl_easy_setopt(this->client, CURLOPT_UPLOAD, 0);
    curl_easy_setopt(this->client, CURLOPT_VERBOSE, 0);
}

EsxApi::~EsxApi() {
    curl_easy_cleanup(this->client);
    curl_slist_free_all(this->headers);
}

std::string
EsxApi::buildRequest(std::string method, std::string morefType,
                     RequestParams params, std::string rawParams) {
    std::stringstream ss;
    ss << ESX_VI__SOAP__REQUEST_HEADER;
    ss << "<" << method << " xmlns=\"urn:vim25\">";
    ss << "<_this xmlns=\"urn:vim25\" xsi:type=\"ManagedObjectReference\" type=\""
       << morefType << "\">";
    if (morefType == "PropertyCollector") {
        ss << this->propertyCollector << "</_this>";
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
EsxApi::buildCustomRequest(std::string method, RequestParam morefType,
                           RequestParams params, std::string rawParams) {
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

ApiObject
EsxApi::ExecuteRequest(std::string method, std::string morefType,
                       RequestParams params, std::string rawParams,
                       std::string rawRequest) {
    auto request = rawRequest;
    if (request.size() == 0) {
        request = buildRequest(method, morefType, params, rawParams);
    }
    std::string content;
    // std::cout << request << "\n";
    curl_easy_setopt(this->client, CURLOPT_POSTFIELDS, request.c_str());
    curl_easy_setopt(this->client, CURLOPT_POSTFIELDSIZE,
                     strlen(request.c_str()));
    curl_easy_setopt(this->client, CURLOPT_WRITEDATA, &content);

    CURLcode errorCode;
    long responseCode;
    errorCode = curl_easy_perform(client);
    if (errorCode != CURLE_OK) {
        std::cerr << curl_easy_strerror(errorCode) << std::endl;
    }
    errorCode =
            curl_easy_getinfo(this->client, CURLINFO_RESPONSE_CODE, &responseCode);
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
EsxApi::RetrieveProperties(std::string type, RequestParam object,
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

    return ExecuteRequest("RetrieveProperties", "PropertyCollector", {},
                          params.str());
}

ApiObject
EsxApi::getServiceContext() {
    auto serviceContent =
            ExecuteRequest("RetrieveServiceContent", "ServiceInstance");
    this->rootFolder = (serviceContent >> "rootFolder")[0]().asString();
    this->sessionManager = (serviceContent >> "sessionManager")[0]().asString();
    this->propertyCollector =
            (serviceContent >> "propertyCollector")[0]().asString();
    this->version =
            ((serviceContent >> "about")[0] >> "fullName")[0]().asString();
    return serviceContent;
}

void
EsxApi::determineHostFolder() {
    auto rootFolderReq = RetrieveProperties(
            "Folder", {.name = "Folder", .value = this->rootFolder},
            {{.name = "name", .type = "string"}},
            {{.name = "name", .type = "string", .value = "folderToChildEntity"},
             {.name = "type", .type = "string", .value = "Folder"},
             {.name = "path", .type = "string", .value = "childEntity"},
             {.name = "skip", .type = "boolean", .value = "false"}});
    auto dcVal = (((rootFolderReq >> "propSet")[0]) >> "val")[0]().asString();
    if (dcVal == "Datacenters") {
        // get the datacenter
        auto datacenter = RetrieveProperties(
                "Datacenter", {.name = "Folder", .value = this->rootFolder},
                {{.name = "name", .type = "string"},
                 {.name = "hostFolder", .type = "string"},
                 {.name = "vmFolder", .type = "string"}},
                {{.name = "name", .type = "string", .value = "folderToChildEntity"},
                 {.name = "type", .type = "string", .value = "Folder"},
                 {.name = "path", .type = "string", .value = "childEntity"},
                 {.name = "skip", .type = "boolean", .value = "false"}});
        this->hostFolder =
                (((datacenter >> "propSet")[0]) >> "val")[0]().asString();
    } else {
        this->hostFolder = "ha-folder-host";
    }
}

void
EsxApi::determineHosts() {
    auto resource = RetrieveProperties(
            "ComputeResource", {.name = "Folder", .value = hostFolder},
            {{.name = "name", .type = "string"},
             {.name = "host", .type = "string"},
             {.name = "resourcePool", .type = "string"}},
            {{.name = "name", .type = "string", .value = "folderToChildEntity"},
             {.name = "type", .type = "string", .value = "Folder"},
             {.name = "path", .type = "string", .value = "childEntity"},
             {.name = "skip", .type = "boolean", .value = "false"}});

    auto domain = (resource >> "obj")[0]().asString();
    auto propSets = (resource >> "propSet");
    for (auto &pset : propSets) {
        auto name = (pset >> "name")[0]().asString();
        if (name == "host") {
            auto vals = (pset >> "val");
            for (auto &val : vals) {
                auto moref = (val >> "ManagedObjectReference");
                for (auto &host : moref) {
                    this->hostNames.push_back(host().asString());
                }
            }
        }
    }
}

ApiObject
EsxApi::Login(std::string username, std::string password) {
    this->getServiceContext();
    auto request = buildCustomRequest(
            "Login", {.name = this->sessionManager, .type = "SessionManager"},
            {{.name = "userName", .value = username, .type = "string"},
             {.name = "password", .value = password, .type = "string"}});

    auto req = ExecuteRequest("Login", "SessionManager", {}, {}, request);
    this->determineHostFolder();
    this->determineHosts();
    return req;
}
