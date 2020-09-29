#include "request-service.h"

#include "Constants.h"
#include "exceptions/invalid-response-exception.h"
#include "tools/object-to-string.h"

#include <Poco/JSON/Parser.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/HTTPSClientSession.h>

namespace network {
RequestService::RequestService(std::shared_ptr<auth::models::AuthConfiguration> auth_configuration) {
  auth_configuration_ = std::move(auth_configuration);
  ssl_context_ = new Context(Context::CLIENT_USE, "", "", "",
                             Context::VERIFY_NONE, 9, true);
}

Object::Ptr RequestService::requestSync(const std::string &endpoint, const Object::Ptr body_object) const noexcept(false) {
  HTTPSClientSession request_session("hwsj-eu-3.9longe.net", HTTPSClientSession::HTTPS_PORT, ssl_context_);
  HTTPRequest http_request(HTTPRequest::HTTP_POST, "/frontend/" + endpoint, HTTPRequest::HTTP_1_1);
  const std::string request_body = core::tools::ObjectToString{}(body_object);
  fillDefaultHeaders(http_request, auth_configuration_->region_id, request_body.length());
  request_session.sendRequest(http_request) << request_body;

  Parser json_parser;
  HTTPResponse http_response;
  std::istream &response_stream = request_session.receiveResponse(http_response);
  if (http_response.getStatus() == HTTPResponse::HTTP_OK) {
    return json_parser.parse(response_stream).extract<Object::Ptr>();
  }
  throw exceptions::InvalidResponseException(http_response.getReason().c_str(), http_response.getStatus());
}

void RequestService::fillDefaultHeaders(HTTPRequest &request, const std::string &region_id,
                                        std::streamsize content_length) {
  request.setContentLength(content_length);
  request.setContentType("application/json; charset=UTF-8");
  request.set("App-Key", constants::kAppKey);
  request.set("Retail-Id", constants::kRetailId);
  request.set("Logical-Region-Id", region_id);
  request.set("User-Agent", "Dalvik/2.1.0");
  request.set("Connection", "close");
  request.set("Accept-Encoding", "gzip, deflate");
}

void RequestService::fillDefaultObjectProperties(Object::Ptr object) {
  object->set("version", "1.8");
  object->set("app_id", constants::kAppId);
}
}// namespace network
