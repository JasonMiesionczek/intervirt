import json
import os

header_template = """
#ifndef <NS>_<CLS>_H
#define <NS>_<CLS>_H

#include <common/util.h>
#include <drivers/hyperv/wmi/AbstractWmiObject.h>

namespace Drivers {
namespace Hyperv {
namespace Wmi {
namespace Classes {
namespace <Ns> {
typedef struct _<cls>_Data {
<struct_fields>
} <cls>_Data;
SER_DECLARE_TYPE(<cls>_Data);
typedef struct _<cls> {
    XmlSerializerInfo *serializerInfo;
    <cls>_Data *data;
} <cls>;

#define <CLS>_RESOURCE_URI \\
    "<uri>"

#define <CLS>_CLASSNAME \\
    "<cls>"

#define <CLS>_WQL_SELECT \\
    "select * from <cls> "

class <clsSmall> : public AbstractWmiObject
{
public:
  <clsSmall>();
};
}
}
}
}
}
#endif /* <NS>_<CLS>_H */

"""

body_template = """
#include "<cls>.h"

namespace Drivers {
namespace Hyperv {
namespace Wmi {
namespace Classes {
namespace <Ns> {

SER_START_ITEMS(<cls>_Data)
<fields>
SER_END_ITEMS(<cls>_Data);

<clsSmall>::<clsSmall>()
        :AbstractWmiObject(
            <CLS>_WQL_SELECT,
            <CLS>_CLASSNAME,
            "<NS>",
            <CLS>_RESOURCE_URI,
            <cls>_Data_TypeInfo
        ) {}

}
}
}
}
}
"""

namespace_header_template = """
#ifndef <NS>_ALL_H
#define <NS>_ALL_H

<classes>

#endif
"""

class Namespace:
    def __init__(self, name, ns, classes):
        self.name = name
        self.ns = ns
        self.classes = classes
        self.output_dir = os.path.join(os.getcwd(), self.name)
        self.process_classes()
        

    def process_classes(self):
        real_classes = []
        for c in self.classes:
            if c['name'] == "" or c['uri'] == "" or len(c['fields']) == 0:
                continue
            real_classes.append(Class(name=c['name'], uri=c['uri'], fields=c['fields'], namespace=self))
        self.classes = real_classes

    def gen_class_files(self, cls):
        output_header_name = os.path.join(self.output_dir, cls.name + '.h')
        output_body_name = os.path.join(self.output_dir, cls.name + '.cpp')
        print output_header_name
        print output_body_name
        upper_cls = cls.name.upper()
        upper_ns = self.name.upper()
        cls_small = cls.name.replace('_', '')
        cap_ns = self.name[:1].upper() + self.name[1:]
        header = header_template.replace('<NS>', upper_ns)
        header = header.replace('<CLS>', upper_cls)
        header = header.replace('<ns>', self.name)
        header = header.replace('<cls>', cls.name)
        header = header.replace('<uri>', cls.uri)
        header = header.replace('<clsSmall>', cls_small)
        header = header.replace('<Ns>', cap_ns)
        header = cls.gen_struct(header)

        body = body_template.replace('<Ns>', cap_ns)
        body = body.replace('<cls>', cls.name)
        body = body.replace('<ns>', self.name)
        body = body.replace('<clsSmall>', cls_small)
        body = body.replace('<CLS>', upper_cls)
        body = body.replace('<NS>', self.ns)
        body = cls.gen_xml_def(body)
        print header
        with open(output_header_name, 'w') as output_header_file:
            output_header_file.write(header)
        with open(output_body_name, 'w') as output_body_file:
            output_body_file.write(body)
        print body

    def gen_all_class_header(self):
        output_all_name = os.path.join(self.output_dir, self.name + '.h')
        ns_header = namespace_header_template.replace('<NS>', self.name.upper())
        classes = ''
        for c in self.classes:
            classes += "#include <drivers/hyperv/wmi/classes/%s/%s.h>\n" % (self.name, c.name)
        ns_header = ns_header.replace('<classes>', classes)
        with open(output_all_name, 'w') as output_all_file:
            output_all_file.write(ns_header)
        print ns_header
        

class Class:
    def __init__(self, name, uri, fields, namespace):
        self.name = name
        self.uri = uri
        self.fields = fields
        self.namespace = namespace
        self.process_fields()

    def process_fields(self):
        real_fields = []
        for f in self.fields:
            real_fields.append(Field(name=f['name'], type=f['type'], cls=self))
        self.fields = real_fields

    def gen_struct(self, header):
        struct_fields = ''
        for f in self.fields:
            struct_fields += f.gen_struct_entry()
        return header.replace('<struct_fields>', struct_fields)

    def gen_xml_def(self, body):
        xml_def_fields = ''
        for f in self.fields:
            xml_def_fields += f.gen_xml_entry()
        return body.replace('<fields>', xml_def_fields)

class Field:
    typemap = {"boolean"  : "BOOL",
               "string"   : "STR",
               "datetime" : "STR",
               "int8"     : "INT8",
               "int16"    : "INT16",
               "int32"    : "INT32",
               "int64"    : "INT64",
               "sint8"    : "INT8",
               "sint16"   : "INT16",
               "uint8"    : "UINT8",
               "uint16"   : "UINT16",
               "uint32"   : "UINT32",
               "uint64"   : "UINT64"}

    def __init__(self, name, type, cls):
        #if type not in Field.typemap:
        #    report_error("unhandled property type %s" % type)

        self.name = name
        self.type = type
        self.cls = cls
        if self.type.endswith('[]'):
            self.is_array = True
            self.type = self.type[:-2]
        else:
            self.is_array = False

    def gen_struct_entry(self):
        if self.is_array:
            return "    XML_TYPE_DYN_ARRAY %s;\n" % self.name
        else:
            return "    XML_TYPE_%s %s;\n" % (Field.typemap[self.type], self.name)

    def gen_xml_entry(self):
        if self.is_array:
            return "    SER_NS_DYN_ARRAY(%s_RESOURCE_URI, \"%s\", 0, 0, %s),\n" \
                    % (self.cls.name.upper(), self.name, self.type)
        else:
            return "    SER_NS_%s(%s_RESOURCE_URI, \"%s\", 1),\n" \
                    % (Field.typemap[self.type], self.cls.name.upper(), self.name)


namespaces = []

with open('classes.json') as json_data:
    d = json.load(json_data)
    print(d['namespaces'])
    
    for namespace in d['namespaces']:
        namespaces.append(Namespace(name=namespace['name'], ns=namespace['ns'], classes=namespace['classes']))
        print(namespace['name'])

for ns in namespaces:
    for cls in ns.classes:
        ns.gen_class_files(cls)
    ns.gen_all_class_header()

    # with open('classes.json', 'w') as outfile:
    #     json.dump(d, outfile, indent=4, separators=(',', ':'))