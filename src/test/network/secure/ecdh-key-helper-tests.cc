#include "network/secure/ecdh-key-helper.h"
#include <Poco/Crypto/CryptoException.h>
#include <gtest/gtest.h>

TEST(ECDHKeyHelper, Should_GeneratePublicKeySuccessfuly) {
  const auto key_helper = std::make_unique<network::secure::ECDHKeyHelper>();
  const auto result = key_helper->GetPublicKey();
  ASSERT_FALSE(result.empty());
}

TEST(ECDHKeyHelper, Should_GenerateSecrecKeyHavingServerPublicKey) {
  const auto key_helper = std::make_unique<network::secure::ECDHKeyHelper>();
  const auto result = key_helper->GetPublicKey();

  const auto key = key_helper->GetSharedKey(R"(-----BEGIN PUBLIC KEY-----
MFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEFmDoErivD8CEqYXQCqIH0s/QxYPJ
0P9ETWBk+wSrw4QPmz0ew8sx9Fxw+ze9glB6PHzGYfXtjtjwY61WbfLwyQ==
-----END PUBLIC KEY-----)");
  ASSERT_TRUE(key.length() == 44);
}
