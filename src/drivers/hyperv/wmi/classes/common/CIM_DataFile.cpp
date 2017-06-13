
#include "CIM_DataFile.h"

namespace Drivers {
    namespace Hyperv {
        namespace Wmi {
            namespace Classes {
                namespace Common {

                    SER_START_ITEMS(CIM_DataFile_Data)
                        SER_NS_UINT32(COMMON_CIM_DATAFILE_RESOURCE_URI, "AccessMask", 1),
                        SER_NS_BOOL(COMMON_CIM_DATAFILE_RESOURCE_URI, "Archive", 1),
                        SER_NS_STR(COMMON_CIM_DATAFILE_RESOURCE_URI, "Caption", 1),
                        SER_NS_BOOL(COMMON_CIM_DATAFILE_RESOURCE_URI, "Compressed", 1),
                        SER_NS_STR(COMMON_CIM_DATAFILE_RESOURCE_URI, "CompressionMethod", 1),
                        SER_NS_STR(COMMON_CIM_DATAFILE_RESOURCE_URI, "CreationClassName", 1),
                        SER_NS_STR(COMMON_CIM_DATAFILE_RESOURCE_URI, "CreationDate", 1),
                        SER_NS_STR(COMMON_CIM_DATAFILE_RESOURCE_URI, "CSCreationClassName", 1),
                        SER_NS_STR(COMMON_CIM_DATAFILE_RESOURCE_URI, "CSName", 1),
                        SER_NS_STR(COMMON_CIM_DATAFILE_RESOURCE_URI, "Description", 1),
                        SER_NS_STR(COMMON_CIM_DATAFILE_RESOURCE_URI, "Drive", 1),
                        SER_NS_STR(COMMON_CIM_DATAFILE_RESOURCE_URI, "EightDotThreeFileName", 1),
                        SER_NS_BOOL(COMMON_CIM_DATAFILE_RESOURCE_URI, "Encrypted", 1),
                        SER_NS_STR(COMMON_CIM_DATAFILE_RESOURCE_URI, "EncryptionMethod", 1),
                        SER_NS_STR(COMMON_CIM_DATAFILE_RESOURCE_URI, "Extension", 1),
                        SER_NS_STR(COMMON_CIM_DATAFILE_RESOURCE_URI, "FileName", 1),
                        SER_NS_UINT64(COMMON_CIM_DATAFILE_RESOURCE_URI, "FileSize", 1),
                        SER_NS_STR(COMMON_CIM_DATAFILE_RESOURCE_URI, "FileType", 1),
                        SER_NS_STR(COMMON_CIM_DATAFILE_RESOURCE_URI, "FSCreationClassName", 1),
                        SER_NS_STR(COMMON_CIM_DATAFILE_RESOURCE_URI, "FSName", 1),
                        SER_NS_BOOL(COMMON_CIM_DATAFILE_RESOURCE_URI, "Hidden", 1),
                        SER_NS_STR(COMMON_CIM_DATAFILE_RESOURCE_URI, "InstallDate", 1),
                        SER_NS_UINT64(COMMON_CIM_DATAFILE_RESOURCE_URI, "InUseCount", 1),
                        SER_NS_STR(COMMON_CIM_DATAFILE_RESOURCE_URI, "LastAccessed", 1),
                        SER_NS_STR(COMMON_CIM_DATAFILE_RESOURCE_URI, "LastModified", 1),
                        SER_NS_STR(COMMON_CIM_DATAFILE_RESOURCE_URI, "Manufacturer", 1),
                        SER_NS_STR(COMMON_CIM_DATAFILE_RESOURCE_URI, "Name", 1),
                        SER_NS_STR(COMMON_CIM_DATAFILE_RESOURCE_URI, "Path", 1),
                        SER_NS_BOOL(COMMON_CIM_DATAFILE_RESOURCE_URI, "Readable", 1),
                        SER_NS_STR(COMMON_CIM_DATAFILE_RESOURCE_URI, "Status", 1),
                        SER_NS_BOOL(COMMON_CIM_DATAFILE_RESOURCE_URI, "System", 1),
                        SER_NS_STR(COMMON_CIM_DATAFILE_RESOURCE_URI, "Version", 1),
                        SER_NS_BOOL(COMMON_CIM_DATAFILE_RESOURCE_URI, "Writeable", 1),

                    SER_END_ITEMS(CIM_DataFile_Data);
                    
                    CIMDataFileMeta::CIMDataFileMeta()
                            :AbstractWmiObject(
                                COMMON_CIM_DATAFILE_WQL_SELECT,
                                COMMON_CIM_DATAFILE_CLASSNAME,
                                "http://schemas.microsoft.com/wbem/wsman/1/wmi/root/cimv2/*",
                                COMMON_CIM_DATAFILE_RESOURCE_URI,
                                CIM_DataFile_Data_TypeInfo
                            ) {}

                }
            }
        }
    }
}
