#ifndef CORE_MISC_AUTH_CONFIGURATION_H_
#define CORE_MISC_AUTH_CONFIGURATION_H_

#include "misc/session-configuration.h"

#include <memory>
#include <string>

namespace network::auth::models {
  class AuthConfiguration {
   public:
    AuthConfiguration(std::shared_ptr<misc::SessionConfiguration> session_configuration);

    std::string region_id;
  };
}

#endif //CORE_MISC_AUTH_CONFIGURATION_H_
