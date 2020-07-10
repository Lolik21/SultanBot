#ifndef CORE_NETWORK_AUTH_AUTH_SERVICE_H_
#define CORE_NETWORK_AUTH_AUTH_SERVICE_H_

#include <memory>
#include "AuthConfiguration.h"

namespace network::auth {
class AuthService {
 public:
  AuthService(std::shared_ptr<AuthConfiguration> auth_configuration);

  void authenticate();
private:
  std::shared_ptr<AuthConfiguration> auth_configuration_;
};
}


#endif //CORE_NETWORK_AUTH_AUTH_SERVICE_H_
