#include "WmiHelper.h"

namespace Drivers {
namespace Hyperv {
namespace Wmi {
WmiHelper::WmiHelper(Connection::ConnectionPtr conn)
{
  this->client_ =
    wsmc_create(conn->getHost().c_str(), 5985, "/wsman", "http",
                conn->getUsername().c_str(), conn->getPassword().c_str());
  wsmc_transport_init(this->client_, NULL);
  wsman_transport_set_auth_method(this->client_, "basic");
}

WmiHelper::~WmiHelper()
{
}

// void WmiHelper::FreeResults(std::vector<WmiObject *> results)
// {

// }

std::vector<WmiObject*>
WmiHelper::GenericEnumerate(std::string query_string, std::string resourceUri,
                            std::string className, std::string ns,
                            XmlSerializerInfo* serializerInfo)
{
  WsSerializerContextH serializerContext;
  client_opt_t* options = NULL;
  filter_t* filter = NULL;
  WsXmlDocH response = NULL;
  char* enumContext = NULL;
  WsXmlNodeH node = NULL;
  XML_TYPE_PTR data = NULL;
  WmiObject* object;
  object = NULL;
  serializerContext = wsmc_get_serialization_context(this->client_);
  options = wsmc_options_init();
  filter = filter_create_simple(WSM_WQL_FILTER_DIALECT, query_string.c_str());
  response = wsmc_action_enumerate(this->client_, ns.c_str(), options, filter);
  enumContext = wsmc_get_enum_context(response);
  ws_xml_destroy_doc(response);
  response = NULL;

  std::vector<WmiObject*> objects;

  while (enumContext != NULL && *enumContext != '\0') {
    response = wsmc_action_pull(this->client_, resourceUri.c_str(), options,
                                filter, enumContext);

    node = ws_xml_get_soap_body(response);
    node = ws_xml_get_child(node, 0, XML_NS_ENUMERATION, WSENUM_PULL_RESP);
    node = ws_xml_get_child(node, 0, XML_NS_ENUMERATION, WSENUM_ITEMS);

    if (ws_xml_get_child(node, 0, resourceUri.c_str(), className.c_str()) ==
        NULL)
      break;

    data = ws_deserialize(serializerContext, node, serializerInfo,
                          className.c_str(), resourceUri.c_str(), NULL, 0, 0);

    object = (WmiObject*)calloc(1, sizeof(WmiObject));
    object->serializerInfo = serializerInfo;
    object->data = data;
    objects.push_back(object);
    data = NULL;

    free(enumContext);
    enumContext = wsmc_get_enum_context(response);

    ws_xml_destroy_doc(response);
    response = NULL;
  }
  wsmc_options_destroy(options);
  filter_destroy(filter);
  // ws_serializer_free_mem(serializerContext, data, serializerInfo);
  ws_xml_destroy_doc(response);
  free(enumContext);

  return objects;
}
} // namespace Wmi
} // namespace Hyperv
} // namespace Drivers
