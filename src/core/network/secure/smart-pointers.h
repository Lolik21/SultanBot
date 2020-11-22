#ifndef CORE_NETWORK_SECURE_SMART_KEYS_H
#define CORE_NETWORK_SECURE_SMART_KEYS_H
#include <memory>
#include <openssl/ec.h>
#include <openssl/evp.h>

namespace network::secure {
struct ECKeyDeleter {
  void operator()(EC_KEY *key) const { EC_KEY_free(key); }
};

struct BIODeleter {
  void operator()(BIO *bio) const { BIO_free(bio); }
};

struct ECGroupDeleter {
  void operator()(EC_GROUP *group) const { EC_GROUP_free(group); }
};

struct ECPointDeleter
{
  void operator()(EC_POINT *point) const { EC_POINT_free(point); }
};

struct EVPCipherDeleter {
  void operator()(EVP_CIPHER_CTX *context) const { EVP_CIPHER_CTX_free(context); }
};

typedef std::unique_ptr<EC_KEY, ECKeyDeleter> SmartECKey;
typedef std::unique_ptr<BIO, BIODeleter> SmartBIO;
typedef std::unique_ptr<EC_GROUP, ECGroupDeleter> SmartECGroup;
typedef std::unique_ptr<EC_POINT, ECPointDeleter> SmartECPoint;
typedef std::unique_ptr<EVP_CIPHER_CTX, EVPCipherDeleter> SmartEVPCipherContext;
}// namespace network::secure

#endif// CORE_NETWORK_SECURE_SMART_KEYS_H
