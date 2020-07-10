#ifndef CORE_MISC_AUTH_CONFIGURATION_H_
#define CORE_MISC_AUTH_CONFIGURATION_H_

#include "../../misc/SessionConfiguration.h"

namespace network::auth {
  class AuthConfiguration {
   public:
    AuthConfiguration(std::shared_ptr<misc::SessionConfiguration> session_configuration);
  };
}

#endif //CORE_MISC_AUTH_CONFIGURATION_H_
