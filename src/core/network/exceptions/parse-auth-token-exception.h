#ifndef CORE_NETWORK_PARSE_AUTH_TOKEN_EXCEPTION_H
#define CORE_NETWORK_PARSE_AUTH_TOKEN_EXCEPTION_H
#include "include/core-expection.h"

namespace network::exceptions {
class ParseAuthTokenException: public CoreException {
 public:
  ParseAuthTokenException() = default;

  explicit ParseAuthTokenException(char const *_Message)
      : CoreException(_Message) {
  }

  ParseAuthTokenException(char const *_Message, int i)
      : CoreException(_Message, i) {
  }

  explicit ParseAuthTokenException(exception const &_Other)
      : CoreException(_Other) {
  }
};
}// namespace network::exceptions

#endif// CORE_NETWORK_PARSE_AUTH_TOKEN_EXCEPTION_H
