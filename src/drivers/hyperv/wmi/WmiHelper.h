#ifndef WMIHELPER_H
#define WMIHELPER_H

#include <openwsman/wsman-api.h>

#include <common/util.h>
#include <objects/HypervisorConnection.h>

namespace Drivers {
    namespace Hyperv {
        namespace Wmi {
            typedef struct _wmiObject {
                XmlSerializerInfo *serializerInfo;
                XML_TYPE_PTR data;
            } WmiObject;

            class WmiHelper {
            public:
                WmiHelper(Connection::ConnectionPtr conn);

                ~WmiHelper();

                template<typename T>
                void FreeResults(std::vector<T *> results) {
                    auto context = wsmc_get_serialization_context(this->client_);
                    for (auto o : results) {
                        ws_serializer_free_mem(context, o->data, o->serializerInfo);
                    }
                }

                template<typename T, typename O>
                std::vector<T *> Enumerate() {
                    auto source = MKSHRD(O);
                    auto query_string = source->getQueryString();

                    return this->Enumerate<T, O>(query_string, source);
                }

                template<typename T, typename O>
                std::vector<T *> Enumerate(std::string query_string, SHRDPTR(O) source = MKSHRD(O)) {
                    auto resourceUri = source->getResourceUri();
                    auto className = source->getClassName();
                    auto ns = source->getNamespace();
                    auto info = source->getSerializerInfo();
                    auto result = this->GenericEnumerate(query_string, resourceUri, className, ns, info);
                    std::vector<WmiObject *>::size_type numObjects = result.size();
                    std::vector<T *> realObjects;
                    realObjects.reserve(numObjects);
                    for (std::vector<WmiObject *>::size_type i = 0; i < numObjects; ++i) {
                        realObjects.push_back((T *) result[i]);
                    }
                    return realObjects;
                }

            private:
                WsManClient *client_;

                std::vector<WmiObject *>
                GenericEnumerate(std::string query_string, std::string resourceUri, std::string className,
                                 std::string ns, XmlSerializerInfo *serializerInfo);
            };
        } // namespace Wmi
    } // namespace Hyperv
} // namespace Drivers

#endif /* WMIHELPER_H */
