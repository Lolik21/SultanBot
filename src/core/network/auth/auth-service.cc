#include "auth-service.h"

#include "misc/logger.h"
#include "network/request-service.h"
#include "network/secure/ecdh-key-helper.h"
#include "tools/object-to-string.h"

#include <Poco/Exception.h>
#include <Poco/JSON/Object.h>

namespace network::auth {
AuthService::AuthService(std::shared_ptr<models::AuthConfiguration> auth_configuration,
                         std::shared_ptr<RequestService> request_service,
                         std::shared_ptr<secure::ECDHKeyHelper> ecdh_key_helper) {
  auth_configuration_ = std::move(auth_configuration);
  request_service_ = std::move(request_service);
  ecdh_key_helper_ = std::move(ecdh_key_helper);
}

void AuthService::authenticate() {
  try {
    misc::Logger::logInfo("Starting to authenticate user {}:{}", "Bob", 2);
    const Object::Ptr token_request_body = makeTokenRequestBody();
    const Object::Ptr token_object = request_service_->requestSync(RequestService::ENDPOINT_DISTRIBUTE,
                                                                   token_request_body);
    auth_session_ = std::make_unique<models::AuthSession>(token_object);

    const Object::Ptr jwt_action_body = makeJwtActionRequestBody();
    const Object::Ptr jwt_response_object = request_service_->requestSync(RequestService::ENDPOINT_JWT_ACTION,
                                                                          jwt_action_body);
    jwt_response_object->stringify(std::cout);

  } catch (Poco::Exception &exception) {
    misc::Logger::logError("Error: {}", exception.message());
    throw;
  }
}

Object::Ptr AuthService::makeJwtActionRequestBody() const noexcept(false) {
  Object::Ptr body_object(new Object());
  RequestService::fillDefaultObjectProperties(body_object);

  body_object->set("server_id", "952");// where this value is coming from???
  body_object->set("jwt", auth_session_->token);
  body_object->set("user_id", auth_session_->user_id);
  body_object->set("act_id", "9999");
  // what a fuck this is coming from?
  body_object->set("c_pub", ecdh_key_helper_->GetPublicKey());
  std::cout << ecdh_key_helper_->GetPublicKey() << std::endl;
  return body_object;
}

Object::Ptr AuthService::makeTokenRequestBody() noexcept(false) {
  Object::Ptr body_object(new Object());
  RequestService::fillDefaultObjectProperties(body_object);
  body_object->set("data", makeTokenRequestDataMember());
  body_object->set("act_id", "user_center_json");
  return body_object;
}

std::string AuthService::makeTokenRequestDataMember() noexcept(false) {
  Object data_object;
  data_object.set("lang", "ru");
  data_object.set("RetailId", 2);
  data_object.set("AppId", 1020);
  data_object.set("ActionId", 1203);
  data_object.set("DeviceType", "SM-G930K");
  data_object.set("DeviceOs", "Android5.1.1");
  data_object.set("UidType", "google");
  data_object.set("DeviceId", "343e5c16a5fd0277");
  data_object.set("ThirdUid", "112694432593763051967");
  data_object.set("DCDeviceId", "354630662014451");

  return core::tools::ObjectToString{}(data_object);
}

}// namespace network::auth
