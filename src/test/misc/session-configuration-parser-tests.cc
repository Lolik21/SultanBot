#include <boost/test/unit_test.hpp>
#include <misc/session-configuration-parser.h>

namespace misc {
BOOST_AUTO_TEST_SUITE(SessionConfigurationParserTests)

BOOST_AUTO_TEST_CASE(ParseConfiguration_MustBeParsed_InCaseOfObject) {
  const std::string configuration = R"({ "deviceId": "MyTestDeviceID" })";
  misc::SessionConfigurationParser parser;
  auto configurations = parser.parseConfiguration(configuration);
  BOOST_VERIFY(configurations.size() == 1);
  BOOST_CHECK_EQUAL(configurations[0]->device_id, "MyTestDeviceID");
}

BOOST_AUTO_TEST_CASE(ParseConfiguration_MustBeParsed_InCaseOfArrayWith1Element) {
  const std::string configuration = R"([{ "deviceId": "MyTestDeviceID" }])";
  misc::SessionConfigurationParser parser;
  auto configurations = parser.parseConfiguration(configuration);
  BOOST_VERIFY(configurations.size() == 1);
  BOOST_REQUIRE_EQUAL(configurations[0]->device_id, "MyTestDeviceID");
}

BOOST_AUTO_TEST_CASE(PraseConfiguration_MustThrow_InCaseOfInvalidJson) {
  const std::string configuration = R"([invalid])";
  misc::SessionConfigurationParser parser;
  BOOST_CHECK_THROW(parser.parseConfiguration(configuration), std::exception);
}
BOOST_AUTO_TEST_SUITE_END()
}// namespace misc
