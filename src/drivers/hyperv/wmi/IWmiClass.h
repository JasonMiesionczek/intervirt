#ifndef IWMICLASS_H
#define IWMICLASS_H

#include <string>
#include <time.h>
#include <openwsman/wsman-api.h>

class IWmiClass
{
public:
  
  std::string getResourceUri() { return this->resourceUri_; }
  std::string getNamespace() { return this->namespace_; }
  std::string getClassName() { return this->className_; }
  std::string getSelectQuery() { return this->selectQuery_; }
  XmlSerializerInfo* getSerializerInfo() { return this->serializerInfo; }
  void setRawData(XML_TYPE_PTR d) { this->rawData = d; }
  XML_TYPE_PTR getRawData() { return this->rawData; }
protected:
  IWmiClass(std::string ns, std::string uri, std::string cn, std::string query, XmlSerializerInfo *info)
  {
      this->namespace_ = ns;
      this->resourceUri_ = uri;
      this->className_ = cn;
      this->selectQuery_ = query;
  }
  std::string namespace_;
  std::string resourceUri_;
  std::string className_;
  std::string selectQuery_;
  XmlSerializerInfo *serializerInfo;
  XML_TYPE_PTR rawData;
};

#endif /* IWMICLASS_H */
