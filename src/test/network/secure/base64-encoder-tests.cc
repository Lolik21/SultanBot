#include "network/secure/base64-encoder.h"

#include <gtest/gtest.h>

using namespace network::secure;

TEST(Base64Encoder, EncodeTestString) {
  const std::string test_string = "Mango and Banana are both my friends";
  const auto result = Base64Encoder::Encode(test_string);
  ASSERT_STREQ("TWFuZ28gYW5kIEJhbmFuYSBhcmUgYm90aCBteSBmcmllbmRz", result.c_str());
}

TEST(Base64Encoder, DecodeTestString) {
  const std::string test_string = "RW5jb2RlIHRvIEJhc2U2NCBmb3JtYXQ=";
  const auto result = Base64Encoder::Decode(test_string);
  const std::string result_string(result.begin(), result.end());
  ASSERT_STREQ("Encode to Base64 format", result_string.c_str());
}

TEST(Base64Encoder, EncodeSomeBinaryString) {
  const std::vector<char> test_string { 13, 92, 12, 123, 84, 29, 0 };
  const auto result = Base64Encoder::Encode(test_string.data());
  ASSERT_STREQ("DVwMe1Qd", result.c_str());
}

TEST(Base64Encoder, DecodeToSomeBinaryString) {
  const std::string test_string = "w57pmYXnrKIbmrZbmrZ3mrp3mrJTDpg=";
  const auto result = Base64Encoder::Decode(test_string);
  const std::string result_string(result.begin(), result.end());
  ASSERT_STREQ("\xC3\x9E\xE9\x99\x85\xE7\xAC\xA2\x1B\x9A\xB6[\x9A\xB6w\x9A\xBAw\x9A\xB2S\xE\x98", result_string.c_str());
}

TEST(Base64Encoder, EncodeAndDecodeTestValue) {
  const std::string test_string = "Mango";
  const auto result_encode = Base64Encoder::Encode(test_string);
  const auto result_decode = Base64Encoder::Decode(result_encode);
  const std::string result_decode_string(result_decode.begin(), result_decode.end());
  ASSERT_STREQ(test_string.c_str(), result_decode_string.c_str());
}

TEST(Base64Encoder, EncodeAndDecodeWithBinaryData) {
  const std::vector<char> test_string { 1, 2, 3, 4, 6, 9, 0 };
  const auto result_encode = Base64Encoder::Encode(test_string.data());
  const auto result_decode = Base64Encoder::Decode(result_encode);
  const std::string result_decode_string(result_decode.begin(), result_decode.end());
  ASSERT_STREQ(test_string.data(), result_decode_string.c_str());
}

