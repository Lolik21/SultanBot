#ifndef CORE_NETWORK_EXCEPTIONS_INVALID_RESPONSE_EXCEPTION_H
#define CORE_NETWORK_EXCEPTIONS_INVALID_RESPONSE_EXCEPTION_H
#include "include/core-expection.h"

namespace network::exceptions {
class InvalidResponseException : public CoreException {
 public:
  InvalidResponseException() = default;

  explicit InvalidResponseException(char const *_Message)
      : CoreException(_Message) {
  }

  InvalidResponseException(char const *_Message, int i)
      : CoreException(_Message, i) {
  }

  explicit InvalidResponseException(exception const &_Other)
      : CoreException(_Other) {
  }
};
}// namespace network::exceptions

#endif// CORE_NETWORK_EXCEPTIONS_INVALID_RESPONSE_EXCEPTION_H
