#include "ecdh-key-helper.h"

#include "base64-encoder.h"
#include "network/exceptions/secure-facilities-expection.h"
#include "smart-pointers.h"

#include <iostream>
#include <openssl/ec.h>
#include <openssl/pem.h>

namespace network::secure {

std::string ECDHKeyHelper::GetPublicKey() {
  if (session_key_ == nullptr) {
    GeneratePublicKey();
  }

  const SmartBIO smart_bio(BIO_new(BIO_s_mem()));
  if (!smart_bio) {
    throw exceptions::SecureFacilitiesException("[ECDHKeyHelper] Failed to allocate BIO for PubKey");
  }
  const int status_success = PEM_write_bio_ECPrivateKey(smart_bio.get(), session_key_.get(), nullptr, nullptr, 0, nullptr, nullptr);
  if (!status_success) {
    throw exceptions::SecureFacilitiesException("[ECDHKeyHelper] Failed to write PUBLIC KEY to BIO");
  }

  size_t read_bytes;
  std::vector<char> key_bytes(1024);
  BIO_read_ex(smart_bio.get(), key_bytes.data(), 1024, &read_bytes);
  return std::string(key_bytes.begin(), key_bytes.begin() + read_bytes);
}

std::string ECDHKeyHelper::GetSharedKey(const std::string &server_key) const
{
  if (!session_key_) {
    throw exceptions::SecureFacilitiesException("[ECDHKeyHelper] Cannot generate sym. server_key without session");
  }

  const SmartBIO smart_bio(BIO_new(BIO_s_mem()));
  int status_success = BIO_write(smart_bio.get(), server_key.data(), static_cast<int>(server_key.length()));
  if (!status_success) {
    throw exceptions::SecureFacilitiesException("[ECDHKeyHelper] Failed to write PEM server_key to BIO");
  }

  const SmartECKey smart_key(PEM_read_bio_EC_PUBKEY(smart_bio.get(), nullptr, nullptr, nullptr));
  if (!smart_key) {
    throw exceptions::SecureFacilitiesException("[ECDHKeyHelper] Failed to create EC Key from BIO");
  }

  const EC_POINT* server_pub_point(EC_KEY_get0_public_key(smart_key.get()));
  std::vector<char> symmetric_key_bytes(128);
  status_success = ECDH_compute_key(symmetric_key_bytes.data(), symmetric_key_bytes.size(),
                                    server_pub_point, session_key_.get(), nullptr);
  if (!status_success) {
    throw exceptions::SecureFacilitiesException("[ECDHKeyHelper] Failed to create EC Key from BIO");
  }
  symmetric_key_bytes.resize(status_success);

  return Base64Encoder::Encode(symmetric_key_bytes.data());
}

void ECDHKeyHelper::GeneratePublicKey() {
  SmartECKey new_key(EC_KEY_new());
  if (!new_key) {
    throw exceptions::SecureFacilitiesException("[ECDHKeyHelper] Failed to create EC_KEY");
  }

  const SmartECGroup prime_group(EC_GROUP_new_by_curve_name(NID_X9_62_prime256v1));
  if (!prime_group) {
    throw exceptions::SecureFacilitiesException("[ECDHKeyHelper] Failed to create Prime256v1 EC group");
  }

  int status_success = EC_KEY_set_group(new_key.get(), prime_group.get());
  if (!status_success) {
    throw exceptions::SecureFacilitiesException("[ECDHKeyHelper] Failed to set EC_KEY group to Prime256v1");
  }

  status_success = EC_KEY_generate_key(new_key.get());
  if (!status_success) {
    throw exceptions::SecureFacilitiesException("[ECDHKeyHelper] Failed to generate EC_KEY");
  }
  session_key_ = std::move(new_key);
}
}// namespace network::secure
