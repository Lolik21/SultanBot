#ifndef CORE_NETWORK_SECURE_BASE_64_ENCODER_H
#define CORE_NETWORK_SECURE_BASE_64_ENCODER_H
#include <string>
#include <vector>

namespace network::secure
{
class Base64Encoder
{
public:
  static std::string Encode(const std::string &input_str);
  static std::string Decode(const std::string &input_str);
};
}

#endif // CORE_NETWORK_SECURE_BASE_64_ENCODER_H
