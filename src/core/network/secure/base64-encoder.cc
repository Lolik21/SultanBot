#include "base64-encoder.h"
#include "network/exceptions/secure-facilities-expection.h"
#include <openssl/evp.h>
#include <vector>

namespace network::secure {
std::string Base64Encoder::Encode(const std::string &input_str) {
  const int size = static_cast<int>((input_str.length() + 2) / 3 * 4);
  std::string result_string(size, '\0');
  const int status = EVP_EncodeBlock(reinterpret_cast<unsigned char *>(result_string.data()),
                                     reinterpret_cast<const unsigned char *>(input_str.data()),
                                     static_cast<int>(input_str.length()));
  if (size != status) {
    throw exceptions::SecureFacilitiesException("[Base64Encoder] Encoding failed");
  }
  return result_string;
}

std::string Base64Encoder::Decode(const std::string &input_str) {
  const auto predicted_size = 3 * input_str.length() / 4;// predict output size
  std::vector<char> output_buffer(predicted_size + 1);
  const std::vector<unsigned char> vec_chars{input_str.begin(), input_str.end()};// convert to_decode into uchar container
  const auto written_bytes = EVP_DecodeBlock(reinterpret_cast<unsigned char *>(output_buffer.data()),
                                             vec_chars.data(), static_cast<int>(vec_chars.size()));

  if (static_cast<int>(predicted_size) != written_bytes) {
    throw exceptions::SecureFacilitiesException("[Base64Encoder] Decode failed");
  }

  return output_buffer.data();
}
}// namespace network::secure
