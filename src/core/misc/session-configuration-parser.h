#ifndef CORE_MISC_SESSION_CONFIGURATION_PARSER_H
#define CORE_MISC_SESSION_CONFIGURATION_PARSER_H
#include "session-configuration.h"

#include <string>
#include <vector>
#include <memory>

namespace misc {
class SessionConfigurationParser {
 public:
  static std::vector<std::shared_ptr<SessionConfiguration>> parseConfiguration(const std::string &configuration);

 private:
  static std::vector<std::shared_ptr<SessionConfiguration>> parseFromArray(const Poco::Dynamic::Var &parsed_config);
  static std::vector<std::shared_ptr<SessionConfiguration>> parseFromObject(const Poco::Dynamic::Var &parsed_config);
  static void pushToConfigurations(const Poco::Dynamic::Var &var, 
      std::vector<std::shared_ptr<SessionConfiguration>> &configurations);
};
}// namespace misc

#endif// CORE_MISC_SESSION_CONFIGURATION_PARSER_H
