//
//  ApiObjectValue.hpp
//  intervirt
//
//  Created by Jason Miesionczek on 12/14/2016.
//
//

#ifndef ApiObjectValue_hpp
#define ApiObjectValue_hpp

#include <common/util.h>

namespace Drivers {
namespace Esx {
namespace Api {

class ApiObjectValue {
public:
  ApiObjectValue(std::string value) : value_(value) {}

  ~ApiObjectValue() = default;
  ApiObjectValue(const ApiObjectValue &other) = default;
  ApiObjectValue(ApiObjectValue &&other) = default;
  ApiObjectValue &operator=(const ApiObjectValue &other) = default;
  ApiObjectValue &operator=(ApiObjectValue &&other) = default;

  std::string asString() { return this->value_; }

private:
  std::string value_;
};
}
}
}

#endif /* ApiObjectValue_hpp */
