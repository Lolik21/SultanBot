#ifndef CORE_NETWORK_REQUEST_SERVICE
#define CORE_NETWORK_REQUEST_SERVICE
#include "auth/models/auth-configuration.h"

#include <Poco/JSON/Object.h>
#include <Poco/Net/Context.h>
#include <Poco/Net/HTTPRequest.h>

namespace network {
using namespace Poco::JSON;
using namespace Poco::Net;

class RequestService {
 public:
  static inline std::string ENDPOINT_DISTRIBUTE = "distribute";
  static inline std::string ENDPOINT_FORWARD = "forward";
  static inline std::string ENDPOINT_JWT_ACTION = "jwt_action";

  RequestService(std::shared_ptr<auth::models::AuthConfiguration>);
  [[nodiscard]] Object::Ptr requestSync(const std::string &endpoint, Object::Ptr body_object) const noexcept(false);

  static void fillDefaultObjectProperties(Object::Ptr object);

 private:
  static void fillDefaultHeaders(HTTPRequest &request, const std::string &region_id, std::streamsize content_length);

  Context::Ptr ssl_context_;
  std::shared_ptr<auth::models::AuthConfiguration> auth_configuration_;
};
}// namespace network

#endif// CORE_NETWORK_REQUEST_SERVICE
