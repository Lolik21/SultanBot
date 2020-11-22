#include "session-configuration.h"
#include <Poco/JSON/Object.h>

namespace misc {
SessionConfiguration::SessionConfiguration(Poco::JSON::Object::Ptr configuration)
{
  name = configuration->get("name").toString();
  device_id = configuration->get("deviceId").toString();
}
}// namespace misc
