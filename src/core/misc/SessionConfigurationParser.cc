#include "SessionConfigurationParser.h"

#include <Poco/JSON/Parser.h>
#include <algorithm>

namespace misc {
std::vector<std::shared_ptr<SessionConfiguration>> SessionConfigurationParser::parseConfiguration(
    const std::string &configuration) {
  using namespace Poco;

  JSON::Parser json_parser;
  const Dynamic::Var parsed_config = json_parser.parse(configuration);
  if (parsed_config.isArray()) {
    return parseFromArray(parsed_config);
  }
  return parseFromObject(parsed_config);
}

std::vector<std::shared_ptr<SessionConfiguration>> SessionConfigurationParser::parseFromArray(
    const Poco::Dynamic::Var &parsed_config) {
  using namespace Poco;
  std::vector<std::shared_ptr<SessionConfiguration>> configurations;
  JSON::Array::Ptr array_ptr = parsed_config.extract<JSON::Array::Ptr>();
  std::for_each(array_ptr->begin(), array_ptr->end(), [&](const Dynamic::Var& element) {
    pushToConfigurations(element, configurations);
  });
  return configurations;
}

std::vector<std::shared_ptr<SessionConfiguration>> SessionConfigurationParser::parseFromObject(
    const Poco::Dynamic::Var &parsed_config) {
  std::vector<std::shared_ptr<SessionConfiguration>> session_configurations;
  pushToConfigurations(parsed_config, session_configurations);
  return session_configurations;
}

void SessionConfigurationParser::pushToConfigurations(const Poco::Dynamic::Var &var, 
    std::vector<std::shared_ptr<SessionConfiguration>> &configurations) {
  using namespace Poco;
  const JSON::Object::Ptr extracted_object = var.extract<JSON::Object::Ptr>();
  configurations.push_back(std::make_shared<SessionConfiguration>(extracted_object));
}
}// namespace misc
