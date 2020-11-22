#ifndef CORE_NETWORK_SECURE_CLIENT_DATA_ENCODER_H
#define CORE_NETWORK_SECURE_CLIENT_DATA_ENCODER_H
#include <string>

namespace network::secure {
class ClientDataEncoder {
 public:
  [[nodiscard]] static std::string Encode(const std::string &key, const std::string &value) noexcept(false);
  [[nodiscard]] static std::string Decode(const std::string &key, const std::string &data) noexcept(false);
};
}// namespace network::secure

#endif// CORE_NETWORK_SECURE_CLIENT_DATA_ENCODER_H
