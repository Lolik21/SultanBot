#ifndef CORE_NETWORK_EXCEPTIONS_SECURE_FACILITIES_EXCEPTION_H
#define CORE_NETWORK_EXCEPTIONS_SECURE_FACILITIES_EXCEPTION_H
#include "include/core-expection.h"

namespace network::exceptions {
class SecureFacilitiesException : public CoreException {
 public:
  SecureFacilitiesException() = default;

  explicit SecureFacilitiesException(char const *_Message)
      : CoreException(_Message) {
  }

  SecureFacilitiesException(char const *_Message, int i)
      : CoreException(_Message, i) {
  }

  explicit SecureFacilitiesException(std::exception const &_Other)
      : CoreException(_Other) {
  }
};
}// namespace network::exceptions

#endif // CORE_NETWORK_EXCEPTIONS_SECURE_FACILITIES_EXCEPTION_H
