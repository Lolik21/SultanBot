#ifndef CORE_TOOLS_OBJECT_TO_STRING_H
#define CORE_TOOLS_OBJECT_TO_STRING_H
#include <Poco/JSON/Object.h>
#include <string>

namespace core::tools {
class ObjectToString {
 public:
  std::string operator()(const Poco::JSON::Object& object) const {
    std::stringstream object_stream;
    object.stringify(object_stream);
    return object_stream.str();
  }

  std::string operator()(const Poco::JSON::Object::Ptr object) const {
    std::stringstream object_stream;
    object->stringify(object_stream);
    return object_stream.str();
  }
};
};// namespace core::tools

#endif// CORE_TOOLS_OBJECT_TO_STRING_H
