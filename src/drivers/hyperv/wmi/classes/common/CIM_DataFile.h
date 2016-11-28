
#ifndef COMMON_CIM_DATAFILE_H
#define COMMON_CIM_DATAFILE_H

#include <common/util.h>
#include <drivers/hyperv/wmi/AbstractWmiObject.h>

namespace Drivers {
namespace Hyperv {
namespace Wmi {
namespace Classes {
namespace Common {
typedef struct _CIM_DataFile_Data {
    XML_TYPE_UINT32 AccessMask;
    XML_TYPE_BOOL Archive;
    XML_TYPE_STR Caption;
    XML_TYPE_BOOL Compressed;
    XML_TYPE_STR CompressionMethod;
    XML_TYPE_STR CreationClassName;
    XML_TYPE_STR CreationDate;
    XML_TYPE_STR CSCreationClassName;
    XML_TYPE_STR CSName;
    XML_TYPE_STR Description;
    XML_TYPE_STR Drive;
    XML_TYPE_STR EightDotThreeFileName;
    XML_TYPE_BOOL Encrypted;
    XML_TYPE_STR EncryptionMethod;
    XML_TYPE_STR Extension;
    XML_TYPE_STR FileName;
    XML_TYPE_UINT64 FileSize;
    XML_TYPE_STR FileType;
    XML_TYPE_STR FSCreationClassName;
    XML_TYPE_STR FSName;
    XML_TYPE_BOOL Hidden;
    XML_TYPE_STR InstallDate;
    XML_TYPE_UINT64 InUseCount;
    XML_TYPE_STR LastAccessed;
    XML_TYPE_STR LastModified;
    XML_TYPE_STR Manufacturer;
    XML_TYPE_STR Name;
    XML_TYPE_STR Path;
    XML_TYPE_BOOL Readable;
    XML_TYPE_STR Status;
    XML_TYPE_BOOL System;
    XML_TYPE_STR Version;
    XML_TYPE_BOOL Writeable;

} CIM_DataFile_Data;
SER_DECLARE_TYPE(CIM_DataFile_Data);
typedef struct _CIM_DataFile {
    XmlSerializerInfo *serializerInfo;
    CIM_DataFile_Data *data;
} CIM_DataFile;

#define CIM_DATAFILE_RESOURCE_URI \
    "http://schemas.microsoft.com/wbem/wsman/1/wmi/root/cimv2/CIM_DataFile"

#define CIM_DATAFILE_CLASSNAME \
    "CIM_DataFile"

#define CIM_DATAFILE_WQL_SELECT \
    "select * from CIM_DataFile "

class CIMDataFile : public AbstractWmiObject
{
public:
  CIMDataFile();
};
}
}
}
}
}
#endif /* COMMON_CIM_DATAFILE_H */

