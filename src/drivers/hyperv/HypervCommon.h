#ifndef HYPERVCOMMON_H
#define HYPERVCOMMON_H

#include <drivers/hyperv/wmi/classes/v1/Win32OperatingSystem.h>
#include <objects/HypervisorConnection.h>
#include <iostream>
#include <vector>
#include <openwsman/wsman-api.h>

class HypervCommon
{
public:
  HypervCommon(Connection::ConnectionPtr conn);

  template<typename T>
    std::vector<T> enumerate()
    {
        static_assert(std::is_base_of<IWmiClass, T>::value, "T must inherit from IWmiClass");
        T objectClass;
        std::vector<T> objects;
        auto selectQuery = objectClass.getSelectQuery().c_str();
        auto ns = objectClass.getNamespace().c_str();
        auto resourceUri = objectClass.getResourceUri().c_str();
        auto className = objectClass.getClassName().c_str();
        WsSerializerContextH serializerContext;
        int result = -1;
        XML_TYPE_PTR data = NULL;
        XmlSerializerInfo *serializerInfo = objectClass.getSerializerInfo();
        serializerContext = wsmc_get_serialization_context(this->client);
        client_opt_t *options = NULL;
        options = wsmc_options_init();
        filter_t *filter = NULL;
        filter = filter_create_simple(WSM_WQL_FILTER_DIALECT, selectQuery);
        WsXmlDocH response = NULL;
        response = wsmc_action_enumerate(this->client, ns, options, filter);
        if (this->verifyResponse(response, "enumeration") < 0) {
            return objects;
        }
        char *enumContext = NULL;
        enumContext = wsmc_get_enum_context(response);
        ws_xml_destroy_doc(response);
        response = NULL;
        WsXmlNodeH node = NULL;
        while (enumContext != NULL && *enumContext != '\0') {
            response = wsmc_action_pull(this->client, resourceUri, options, filter, enumContext);
            if (this->verifyResponse(response, "pull")) {
                return objects;
            }
            node = ws_xml_get_soap_body(response);
            node = ws_xml_get_child(node, 0, XML_NS_ENUMERATION, WSENUM_PULL_RESP);
            node = ws_xml_get_child(node, 0, XML_NS_ENUMERATION, WSENUM_ITEMS);
            if (ws_xml_get_child(node, 0, resourceUri, className) == NULL)
                break;
            data = ws_deserialize(serializerContext, node, serializerInfo,
                              className, resourceUri, NULL, 0, 0);

            objectClass.setRawData(data);
            objects.push_back(objectClass);
            data = NULL;
            enumContext = wsmc_get_enum_context(response);
            ws_xml_destroy_doc(response);
            response = NULL;
        }
        //WsmanFilter filter(WSM_WQL_FILTER_DIALECT, objectClass.getSelectQuery());
        //WsmanOptions options;
        //options.setNamespace(objectClass.getNamespace());
        // try {
        // this->client->Enumerate(
        //     objectClass.getResourceUri(),
        //     result,
        //     options,
        //     filter);
        // } catch (WsmanSoapFault ex) {
        //     std::cout << ex.getDetail() << std::endl;
        // }

        return objects;
    }
  

private:
  int verifyResponse(WsXmlDocH response, const char *detail);
  WsManClient *client;
};

#endif /* HYPERVCOMMON_H */
