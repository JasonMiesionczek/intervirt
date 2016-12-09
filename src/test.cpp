#include <common/util.h>
#include <curl/curl.h>
#include <libxml++/libxml++.h>

# define ESX_VI__SOAP__REQUEST_HEADER                                         \
    "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"                            \
    "<soapenv:Envelope\n"                                                     \
    " xmlns:soapenv=\"http://schemas.xmlsoap.org/soap/envelope/\"\n"          \
    " xmlns:soapenc=\"http://schemas.xmlsoap.org/soap/encoding/\"\n"          \
    " xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"\n"              \
    " xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\">\n"                      \
    "<soapenv:Body>\n"



# define ESX_VI__SOAP__REQUEST_FOOTER                                         \
    "</soapenv:Body>\n"                                                       \
    "</soapenv:Envelope>"

static size_t
esxVI_CURL_ReadString(char *data, size_t size, size_t nmemb, void *userdata)
{
    const char *content = *(const char **)userdata;
    size_t available = 0;
    size_t requested = size * nmemb;

    if (!content)
        return 0;

    available = strlen(content);

    if (available == 0)
        return 0;

    if (requested > available)
        requested = available;

    memcpy(data, content, requested);

    *(const char **)userdata = content + requested;

    return requested;
}

typedef struct _virBuffer virBuffer;
typedef virBuffer *virBufferPtr;

#define VIR_BUFFER_INITIALIZER { 0, 0, 0, 0, NULL }
#define VIR_FREE(ptr) virFree(&(ptr))
#define VIR_REALLOC_N_QUIET(ptr, count) virReallocN(&(ptr), sizeof(*(ptr)), (count), \
                                                     false, 0, NULL, NULL, 0)
#define xalloc_oversized(n, s) \
    ((size_t) (sizeof(ptrdiff_t) <= sizeof(size_t) ? -1 : -2) / (s) < (n))

int virReallocN(void *ptrptr,
                size_t size,
                size_t count,
                bool report,
                int domcode,
                const char *filename,
                const char *funcname,
                size_t linenr)
{
    void *tmp;


    if (xalloc_oversized(count, size)) {
        errno = ENOMEM;
        return -1;
    }
    tmp = realloc(*(void**)ptrptr, size * count);
    if (!tmp && (size * count)) {
        return -1;
    }
    *(void**)ptrptr = tmp;
    return 0;
}

void virFree(void *ptrptr)
{
    int save_errno = errno;

    free(*(void**)ptrptr);
    *(void**)ptrptr = NULL;
    errno = save_errno;
}

/* This struct must be kept in sync with the real struct
   in the buf.c impl file */

struct _virBuffer {
    unsigned int size;
    unsigned int use;
    unsigned int error; /* errno value, or -1 for usage error */
    int indent;
    char *content;
};

int
virBufferGetIndent(const virBuffer *buf, bool dynamic)
{
    if (!buf || buf->error)
        return -1;
    if (dynamic && buf->use && buf->content[buf->use - 1] != '\n')
        return 0;
    return buf->indent;
}

static void
virBufferSetError(virBufferPtr buf, int error)
{
    VIR_FREE(buf->content);
    buf->size = 0;
    buf->use = 0;
    buf->indent = 0;
    buf->error = error;
}

static int
virBufferGrow(virBufferPtr buf, unsigned int len)
{
    int size;

    if (buf->error)
        return -1;

    if ((len + buf->use) < buf->size)
        return 0;

    size = buf->use + len + 1000;

    if (VIR_REALLOC_N_QUIET(buf->content, size) < 0) {
        virBufferSetError(buf, errno);
        return -1;
    }
    buf->size = size;
    return 0;
}

void
virBufferAdd(virBufferPtr buf, const char *str, int len)
{
    unsigned int needSize;
    int indent;

    if (!str || !buf || (len == 0 && buf->indent == 0))
        return;

    indent = virBufferGetIndent(buf, true);
    if (indent < 0)
        return;

    if (len < 0)
        len = strlen(str);

    needSize = buf->use + indent + len + 2;
    if (virBufferGrow(buf, needSize - buf->use) < 0)
        return;

    memset(&buf->content[buf->use], ' ', indent);
    memcpy(&buf->content[buf->use + indent], str, len);
    buf->use += indent + len;
    buf->content[buf->use] = '\0';
}

unsigned int
virBufferUse(const virBuffer *buf)
{
    if (buf == NULL)
        return 0;

    return buf->use;
}

static size_t
esxVI_CURL_WriteBuffer(char *data, size_t size, size_t nmemb, void *userdata)
{
    virBufferPtr buffer = (virBuffer*)userdata;

    if (buffer) {
        /*
         * Using a virBuffer to store the download data limits the downloadable
         * size. This is no problem as esxVI_CURL_Download and esxVI_CURL_Perform
         * are meant to download small things such as VMX files, VMDK metadata
         * files and SOAP responses.
         */
        if (size * nmemb > INT32_MAX / 2 - virBufferUse(buffer))
            return 0;

        virBufferAdd(buffer, data, size * nmemb);

        return size * nmemb;
    }

    return 0;
}

char *
virBufferContentAndReset(virBufferPtr buf)
{
    char *str;
    if (buf == NULL)
        return NULL;

    if (buf->error) {
        memset(buf, 0, sizeof(*buf));
        return NULL;
    }

    str = buf->content;
    memset(buf, 0, sizeof(*buf));
    return str;
}

void print_indentation(unsigned int indentation)
{
  for(unsigned int i = 0; i < indentation; ++i)
    std::cout << " ";
}

void print_node(const xmlpp::Node* node, unsigned int indentation = 0)
{
  std::cout << std::endl; //Separate nodes by an empty line.

  const xmlpp::ContentNode* nodeContent = dynamic_cast<const xmlpp::ContentNode*>(node);
  const xmlpp::TextNode* nodeText = dynamic_cast<const xmlpp::TextNode*>(node);
  const xmlpp::CommentNode* nodeComment = dynamic_cast<const xmlpp::CommentNode*>(node);

  if(nodeText && nodeText->is_white_space()) //Let's ignore the indenting - you don't always want to do this.
    return;

  Glib::ustring nodename = node->get_name();

  if(!nodeText && !nodeComment && !nodename.empty()) //Let's not say "name: text".
  {
    print_indentation(indentation);
    std::cout << "Node name = " << node->get_name() << std::endl;
    std::cout << "Node name = " << nodename << std::endl;
  }
  else if(nodeText) //Let's say when it's text. - e.g. let's say what that white space is.
  {
    print_indentation(indentation);
    std::cout << "Text Node" << std::endl;
  }

  //Treat the various node types differently:
  if(nodeText)
  {
    print_indentation(indentation);
    std::cout << "text = \"" << nodeText->get_content() << "\"" << std::endl;
  }
  else if(nodeComment)
  {
    print_indentation(indentation);
    std::cout << "comment = " << nodeComment->get_content() << std::endl;
  }
  else if(nodeContent)
  {
    print_indentation(indentation);
    std::cout << "content = " << nodeContent->get_content() << std::endl;
  }
  else if(const xmlpp::Element* nodeElement = dynamic_cast<const xmlpp::Element*>(node))
  {
    //A normal Element node:

    //line() works only for ElementNodes.
    print_indentation(indentation);
    std::cout << "     line = " << node->get_line() << std::endl;

    //Print attributes:
    const xmlpp::Element::AttributeList& attributes = nodeElement->get_attributes();
    for(xmlpp::Element::AttributeList::const_iterator iter = attributes.begin(); iter != attributes.end(); ++iter)
    {
      const xmlpp::Attribute* attribute = *iter;
      print_indentation(indentation);
      std::cout << "  Attribute " << attribute->get_name() << " = " << attribute->get_value() << std::endl;
    }

    const xmlpp::Attribute* attribute = nodeElement->get_attribute("title");
    if(attribute)
    {
      std::cout << "title found: =" << attribute->get_value() << std::endl;

    }
  }

  if(!nodeContent)
  {
    //Recurse through child nodes:
    xmlpp::Node::NodeList list = node->get_children();
    for(xmlpp::Node::NodeList::iterator iter = list.begin(); iter != list.end(); ++iter)
    {
      print_node(*iter, indentation + 2); //recursive
    }
  }
}

class ApiObjectValue
{
public:
    ApiObjectValue(std::string value)
        : value_(value) {}

    ~ApiObjectValue() = default;
    ApiObjectValue(const ApiObjectValue& other) = default;
    ApiObjectValue(ApiObjectValue&& other) = default;
    ApiObjectValue& operator=(const ApiObjectValue& other) = default;
    ApiObjectValue& operator=(ApiObjectValue&& other) = default;

    std::string asString() { return this->value_; }
private:
    std::string value_;
};

class ApiObject
{
public:
    ApiObject(std::string name)
        : name_(name), value_(nullptr){}

    ~ApiObject() = default;
    ApiObject(const ApiObject& other) = default;
    ApiObject(ApiObject&& other) = default;
    ApiObject& operator=(const ApiObject& other) = default;
    ApiObject& operator=(ApiObject&& other) = default;

    void addChild(std::string name, std::shared_ptr<ApiObject> obj) { this->children_[name] = obj; }
    void addAttr(std::string name, std::string value) { this->attrs_[name] = std::make_shared<ApiObjectValue>(value); }
    void setValue(std::string value) { this->value_ = std::make_shared<ApiObjectValue>(value); }

    ApiObject operator>>(const std::string name) {
        return *this->children_[name];
    }

    ApiObjectValue operator[](const std::string attr) {
        return *this->attrs_[attr];
    }

    ApiObjectValue operator()() {
        return *this->value_;
    }
private:
    std::string name_;
    std::map<std::string, std::shared_ptr<ApiObjectValue>> attrs_;
    std::shared_ptr<ApiObjectValue> value_;
    std::map<std::string, std::shared_ptr<ApiObject>> children_;
};


ApiObject parseResponse(xmlpp::Node* node, std::shared_ptr<ApiObject> object = nullptr)
{
    const xmlpp::ContentNode* nodeContent = dynamic_cast<const xmlpp::ContentNode*>(node);
    const xmlpp::TextNode* nodeText = dynamic_cast<const xmlpp::TextNode*>(node);
    const xmlpp::CommentNode* nodeComment = dynamic_cast<const xmlpp::CommentNode*>(node);
    const xmlpp::Element* nodeElement = dynamic_cast<const xmlpp::Element*>(node);

    auto obj = std::make_shared<ApiObject>(node->get_name());

    if (node->get_name() == "text" && object != nullptr) {
        object->setValue(nodeContent->get_content());
        return *object;
    }

    if (object != nullptr) {
        object->addChild(node->get_name(), obj);
    }

    if (nodeElement) {
        for (auto& attr : nodeElement->get_attributes()) {
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
        for (auto& child : children) {
            parseResponse(child, obj);
        }
    }

    return *obj;
}

int main()
{
    CURL *handle;
    struct curl_slist *headers = NULL;
    char error[CURL_ERROR_SIZE];

    auto url = "https://10.0.21.59:443/sdk";


    handle = curl_easy_init();
    headers = curl_slist_append(headers, "Content-Type: text/xml; charset=UTF-8");
    headers = curl_slist_append(headers, "Expect:");
    curl_easy_setopt(handle, CURLOPT_USERAGENT, "libvirt-esx");
    curl_easy_setopt(handle, CURLOPT_NOSIGNAL, 1);
    curl_easy_setopt(handle, CURLOPT_HEADER, 0);
    curl_easy_setopt(handle, CURLOPT_FOLLOWLOCATION, 0);
    curl_easy_setopt(handle, CURLOPT_SSL_VERIFYPEER,0);
    curl_easy_setopt(handle, CURLOPT_SSL_VERIFYHOST,0);
    curl_easy_setopt(handle, CURLOPT_COOKIEFILE, "");
    curl_easy_setopt(handle, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(handle, CURLOPT_READFUNCTION, esxVI_CURL_ReadString);
    curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, esxVI_CURL_WriteBuffer);
    curl_easy_setopt(handle, CURLOPT_ERRORBUFFER, error);

    const char *request = ESX_VI__SOAP__REQUEST_HEADER
                            "<RetrieveServiceContent xmlns=\"urn:vim25\">"
                              "<_this xmlns=\"urn:vim25\" "
                                     "xsi:type=\"ManagedObjectReference\" "
                                     "type=\"ServiceInstance\">"
                                "ServiceInstance"
                              "</_this>"
                            "</RetrieveServiceContent>"
                          ESX_VI__SOAP__REQUEST_FOOTER;

    virBuffer buffer = VIR_BUFFER_INITIALIZER;

    curl_easy_setopt(handle, CURLOPT_URL, url);
    curl_easy_setopt(handle, CURLOPT_RANGE, NULL);
    curl_easy_setopt(handle, CURLOPT_WRITEDATA, &buffer);
    curl_easy_setopt(handle, CURLOPT_UPLOAD, 0);
    curl_easy_setopt(handle, CURLOPT_POSTFIELDS, request);
    curl_easy_setopt(handle, CURLOPT_POSTFIELDSIZE, strlen(request));
    //curl_easy_setopt(handle, CURLOPT_DEBUGFUNCTION, esxVI_CURL_Debug);
    curl_easy_setopt(handle, CURLOPT_VERBOSE, 1);
    CURLcode errorCode;
    long responseCode;
    errorCode = curl_easy_perform(handle);
    if (errorCode != CURLE_OK) {
        std::cerr << curl_easy_strerror(errorCode) << std::endl;
    }
    errorCode = curl_easy_getinfo(handle, CURLINFO_RESPONSE_CODE, &responseCode);
    std::cout << responseCode << std::endl;
    auto content = virBufferContentAndReset(&buffer);
    std::cout << content <<std::endl;
    curl_easy_cleanup(handle);
    curl_slist_free_all(headers);

    xmlpp::DomParser parser;
    parser.set_substitute_entities();
    std::stringstream ss;
    ss << content;
    try
    {
        parser.parse_stream(ss);
        if (parser) {
            xmlpp::Element* node = parser.get_document()->get_root_node();
            node->set_namespace_declaration("http://schemas.xmlsoap.org/soap/envelope/", "soapenv");
            node->set_namespace_declaration("urn:vim25", "vim");

            auto n = static_cast<xmlpp::Node*>(node);
            std::map<Glib::ustring, Glib::ustring> nsmap;
            nsmap["soapenv"] = "http://schemas.xmlsoap.org/soap/envelope/";
            nsmap["vim"] = "urn:vim25";
            auto set = n->find("/soapenv:Envelope/soapenv:Body/vim:RetrieveServiceContentResponse", nsmap);
            auto response = set[0];
            auto returnVal = response->find("./vim:returnval", nsmap);
            //print_node(node);
            auto object = parseResponse(returnVal[0]);
            auto about = object >> "about" >> "apiType";
            auto rootFolder = (object >> "rootFolder")["type"].asString();
            std::cout << rootFolder << "\n";
            std::cout << (object >> "about" >> "fullName")().asString() << "\n";
        }
    }
    catch (xmlpp::internal_error e)
    {
        std::cerr << e.what() << std::endl;
    }

    VIR_FREE(buffer);
}
