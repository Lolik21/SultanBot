#include "client-data-encoder.h"

#include "base64-encoder.h"
#include "network/exceptions/secure-facilities-expection.h"
#include "smart-pointers.h"

#include <openssl/evp.h>
#include <vector>

namespace network::secure {
std::string ClientDataEncoder::Encode(const std::string &key, const std::string &value) noexcept(false) {
  const SmartEVPCipherContext cipher_context(EVP_CIPHER_CTX_new());

  int bytes_written{};
  std::vector<char> rc4_out(value.length() + 1);
  EVP_EncryptInit(cipher_context.get(), EVP_rc4(),  nullptr, nullptr);
  EVP_CIPHER_CTX_set_key_length(cipher_context.get(), static_cast<int>(key.length()));
  EVP_EncryptInit(cipher_context.get(), nullptr,  reinterpret_cast<const unsigned char *>(key.data()), nullptr);
  EVP_EncryptUpdate(cipher_context.get(), reinterpret_cast<unsigned char *>(rc4_out.data()), &bytes_written,
                    reinterpret_cast<const unsigned char *>(value.data()), static_cast<int>(value.length()));

  return Base64Encoder::Encode(rc4_out.data());
}

std::string ClientDataEncoder::Decode(const std::string &key, const std::string &data) noexcept(false) {
  const SmartEVPCipherContext cipher_context(EVP_CIPHER_CTX_new());
  const std::string decoded_data = Base64Encoder::Decode(data);

  int bytes_written{};
  std::vector<char> rc4_out(data.length() + 1);
  EVP_DecryptInit(cipher_context.get(), EVP_rc4(),  nullptr, nullptr);
  EVP_CIPHER_CTX_set_key_length(cipher_context.get(), static_cast<int>(key.length()));
  EVP_DecryptInit(cipher_context.get(), nullptr,  reinterpret_cast<const unsigned char *>(key.data()), nullptr);
  EVP_DecryptUpdate(cipher_context.get(), reinterpret_cast<unsigned char *>(rc4_out.data()), &bytes_written,
                    reinterpret_cast<const unsigned char *>(decoded_data.data()), static_cast<int>(decoded_data.length()));
  return rc4_out.data();
}
}// namespace network::secure
