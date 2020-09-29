#include "auth-configuration.h"

namespace network::auth::models {
AuthConfiguration::AuthConfiguration(std::shared_ptr<misc::SessionConfiguration> session_configuration) {
  region_id = "1020";
}
}// namespace network::auth
