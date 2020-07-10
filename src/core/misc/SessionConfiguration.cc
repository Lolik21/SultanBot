#include "SessionConfiguration.h"
#include <Poco/JSON/Object.h>

namespace misc {
SessionConfiguration::SessionConfiguration(Poco::JSON::Object::Ptr configuration)
{
  device_id = configuration->get("deviceId").toString();
}
}// namespace misc
