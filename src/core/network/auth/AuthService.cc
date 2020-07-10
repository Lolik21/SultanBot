#include "AuthService.h"

namespace network::auth {
AuthService::AuthService(std::shared_ptr<AuthConfiguration> auth_configuration):
  auth_configuration_(std::move(auth_configuration)) {
}

void AuthService::authenticate() {
  std::cout << "Starting authentication of device(" << 123 << ")\n";
}
}// namespace network::auth
