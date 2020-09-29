#ifndef CORE_NETWORK_AUTH_AUTH_SERVICE_H_
#define CORE_NETWORK_AUTH_AUTH_SERVICE_H_

#include "models/auth-configuration.h"
#include "models/auth-session.h"
#include "network/request-service.h"

#include <memory>
#include <string>

namespace network::auth {
class AuthService {
 public:
  AuthService(std::shared_ptr<models::AuthConfiguration> auth_configuration,
              std::shared_ptr<RequestService> request_service);
  void authenticate() noexcept(false);

 private:
  [[nodiscard]] Object::Ptr makeJwtActionRequestBody() const noexcept(true);
  [[nodiscard]] static Object::Ptr makeTokenRequestBody() noexcept(true);
  [[nodiscard]] static std::string makeTokenRequestDataMember() noexcept(true);

  std::shared_ptr<models::AuthConfiguration> auth_configuration_;
  std::unique_ptr<models::AuthSession> auth_session_;
  std::shared_ptr<RequestService> request_service_;
};
}// namespace network::auth

#endif//CORE_NETWORK_AUTH_AUTH_SERVICE_H_
