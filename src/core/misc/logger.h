#ifndef CORE_MISC_LOGGER_H
#define CORE_MISC_LOGGER_H

#include <iostream>
#include <regex>

namespace misc {
enum class LogLevel {
  LOG_DEBUG,
  LOG_VERBOSE,
  LOG_INFO,
  LOG_WARNING,
  LOG_ERROR,
};

class Logger {
 public:
  template<class... Args>
  static void logError(std::string format, const Args &... args) {
    if (log_level_ <= LogLevel::LOG_ERROR) {
      logInternal(format, args...);
    }
  }

  template<class... Args>
  static void logInfo(std::string format, const Args &... args) {
    if (log_level_ <= LogLevel::LOG_INFO) {
      logInternal(format, args...);
    }
  }

 private:
  template<class CurrentArg, class... Args>
  static void logInternal(std::string &format, const CurrentArg &arg, const Args &... args) {
    if (std::regex_search(format, template_pattern_)) {
      std::stringstream string_stream;
      string_stream << arg;
      format = std::regex_replace(format, template_pattern_, string_stream.str().c_str(),
                                  std::regex_constants::format_first_only);
      logInternal(format, args...);
    }
  }

  static void logInternal(std::string &format) {
    std::cout << format << std::endl;
  }

  static inline LogLevel log_level_{LogLevel::LOG_INFO};
  static inline std::regex template_pattern_{"\\{.*?\\}"};
};
}// namespace misc

#endif// CORE_MISC_LOGGER_H
