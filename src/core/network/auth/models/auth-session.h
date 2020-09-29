#ifndef CORE_NETWORK_AUTH_AUTH_SESSION_H
#define CORE_NETWORK_AUTH_AUTH_SESSION_H

#include "auth-configuration.h"

#include <set>
#include <string>

namespace network::auth::models {
using namespace Poco;

class AuthSession {
 public:
  AuthSession(JSON::Object::Ptr data_object);

  std::string token{};
  std::string user_id{};
  std::string account{};
  std::string password{};
  int last_status_code{};
  std::set<std::string> third_user_id_list{};

 private:
  static std::set<std::string> extractThirdUserIdList(JSON::Object::Ptr token_response);
};
}// namespace network::auth::models

#endif// CORE_NETWORK_AUTH_AUTH_SESSION_H
