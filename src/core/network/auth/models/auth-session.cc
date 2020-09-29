#include "auth-session.h"

#include "misc/logger.h"
#include "network/exceptions/parse-auth-token-exception.h"

#include <Poco/JSON/Parser.h>

namespace network::auth::models {
AuthSession::AuthSession(JSON::Object::Ptr auth_response_object) {
  JSON::Parser json_parser;
  const auto data_string = auth_response_object->get("data").toString();
  const auto data_object = json_parser.parse(data_string).extract<JSON::Object::Ptr>();
  last_status_code = data_object->get("Stat").convert<int>();
  if (last_status_code == 0) {
    user_id = data_object->get("Uid").toString();
    token = data_object->get("Token").toString();
    account = data_object->get("Account").toString();
    password = data_object->get("Password").toString();
    third_user_id_list = extractThirdUserIdList(data_object);
    return;
  }
  const std::string info = data_object->get("Info").toString();
  misc::Logger::logError("Failed to parse token response. Server status code: {}. Info: \"{}\"", last_status_code, info);
  throw exceptions::ParseAuthTokenException("Server response format error");
}
std::set<std::string> AuthSession::extractThirdUserIdList(JSON::Object::Ptr token_response) {
  std::set<std::string> result_set;
  const JSON::Array::Ptr third_user_id_list = token_response->getArray("ThirdUidList");
  for (auto &&uuid_type_object : *third_user_id_list) {
    result_set.insert(uuid_type_object.extract<JSON::Object::Ptr>()->get("UidType").toString());
  }
  return result_set;
}
}// namespace network::auth::models
