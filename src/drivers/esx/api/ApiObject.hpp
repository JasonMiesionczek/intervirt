//
//  ApiObject.hpp
//  intervirt
//
//  Created by Jason Miesionczek on 14/12/2016.
//
//

#ifndef ApiObject_hpp
#define ApiObject_hpp

#include <common/util.h>
#include <drivers/esx/api/ApiObjectValue.hpp>

namespace Drivers {
namespace Esx {
namespace Api {

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

    void addChild(std::string name, std::shared_ptr<ApiObject> obj) { this->children_[name].push_back(obj); }
    void addAttr(std::string name, std::string value) { this->attrs_[name] = std::make_shared<ApiObjectValue>(value); }
    void setValue(std::string value) { this->value_ = std::make_shared<ApiObjectValue>(value); }

    std::vector<ApiObject> operator>>(const std::string name) {
        std::vector<ApiObject> result;
        for (auto& o : this->children_[name]) {
            result.push_back(*o);
        }
        return result;
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
    std::map<std::string, std::vector<std::shared_ptr<ApiObject>>> children_;
};

}}}

#endif /* ApiObject_hpp */
