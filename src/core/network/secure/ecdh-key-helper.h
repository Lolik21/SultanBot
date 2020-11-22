#ifndef CORE_NETWORK_AUTH_ECDH_KEY_HELPER_H
#define CORE_NETWORK_AUTH_ECDH_KEY_HELPER_H
#include "smart-pointers.h"

#include <string>
#include <vector>

namespace network::secure {
class ECDHKeyHelper {
 public:
  [[nodiscard]] std::string GetPublicKey() noexcept(false);
  [[nodiscard]] std::string GetSharedKey(const std::string& server_key) const noexcept(false);
private:
  void GeneratePublicKey();

  SmartECKey session_key_;
};
}// namespace core::network::auth

#endif// CORE_NETWORK_AUTH_ECDH_KEY_HELPER_H
