#ifndef CORE_NETWORK_AUTH_AUTH_SERVICE_H_
#define CORE_NETWORK_AUTH_AUTH_SERVICE_H_

#include "models/auth-configuration.h"
#include "models/auth-session.h"
#include "network/request-service.h"
#include "network/secure/ecdh-key-helper.h"


#include <memory>
#include <string>

namespace network::auth {
class AuthService {
 public:
  AuthService(
      std::shared_ptr<models::AuthConfiguration> auth_configuration, 
      std::shared_ptr<RequestService> request_service, 
      std::shared_ptr<secure::ECDHKeyHelper> ecdh_key_helper);
  void authenticate() noexcept(false);

 private:
  [[nodiscard]] Object::Ptr makeJwtActionRequestBody() const noexcept(false);
  [[nodiscard]] static Object::Ptr makeTokenRequestBody() noexcept(false);
  [[nodiscard]] static std::string makeTokenRequestDataMember() noexcept(false);

  std::shared_ptr<models::AuthConfiguration> auth_configuration_;
  std::unique_ptr<models::AuthSession> auth_session_;
  std::shared_ptr<RequestService> request_service_;
  std::shared_ptr<secure::ECDHKeyHelper> ecdh_key_helper_;
};
}// namespace network::auth

#endif//CORE_NETWORK_AUTH_AUTH_SERVICE_H_
