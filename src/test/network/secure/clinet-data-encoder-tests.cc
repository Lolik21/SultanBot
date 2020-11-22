#include "network/secure/client-data-encoder.h"
#include <gtest/gtest.h>

using namespace network::secure;

TEST(ClientDataEncoder, ShouldEncodeClientData) {
  const auto result = ClientDataEncoder::Encode("Mango", "Banana");
  ASSERT_STREQ("mblyUHhp", result.c_str());
}

TEST(ClientDataEncoder, ShouldEncodeClientDataWithRealKeys) {
  const auto result = ClientDataEncoder::Encode("2JPyEci/0hzNM3FumdIFobPcmXEaxXXaUIccu6Dwoiw=",
                                                "MangoMangoMangoMangoMangoMangoMangoMango");

  ASSERT_STREQ("8QmhEQqc93AinF7Jlo7u6BqQ2ziWL3mCFLNV+m7UOhDi0tbMVmGiyg==", result.c_str());
}

TEST(ClientDataEncoder, ShoudlDecodeClientData) {
  const std::string key = "2JPyEci/0hzNM3FumdIFobPcmXEaxXXaUIccu6Dwoiw=";
  const std::string value = "8QmhEQqc93AinF7Jlo7u6BqQ2ziWL3mCFLNV+m7UOhDi0tbMVmGiyg==";
  const auto result = ClientDataEncoder::Decode(key, value);
  ASSERT_STREQ("MangoMangoMangoMangoMangoMangoMangoMango", result.c_str());
}

TEST(ClientDataEncoder, EncodedAndDecodedValuesMustBeEqual) {
  const auto result_encode = ClientDataEncoder::Encode("Mandarin", "Apple");
  const auto result_decode = ClientDataEncoder::Decode("Mandarin", result_encode);
  ASSERT_STREQ("Apple", result_decode.c_str());
}
