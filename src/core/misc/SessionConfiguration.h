#ifndef CORE_MISC_SESSION_CONFIGURATION_H
#define CORE_MISC_SESSION_CONFIGURATION_H
#include <string>
#include <Poco/JSON/Object.h>

namespace misc
{
struct SessionConfiguration
{
  SessionConfiguration(Poco::JSON::Object::Ptr configuration);
  
  std::string device_id;
};
}

#endif // CORE_MISC_SESSION_CONFIGURATION_H
