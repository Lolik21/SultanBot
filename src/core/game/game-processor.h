#ifndef SULTANBOT_CORE_GAME_GAME_PROCESSOR_H_
#define SULTANBOT_CORE_GAME_GAME_PROCESSOR_H_

#include <string>
#include "misc/session-configuration.h"

namespace game {
class GameProcessor {
 public:
  GameProcessor();

  static void startGameSession(const std::shared_ptr<misc::SessionConfiguration> &session_configuration);
  static void stopGameSession(const std::string &session_name);
  static void stopAllSessions();
private:
  
};
}// namespace game

#endif//SULTANBOT_CORE_GAME_GAME_PROCESSOR_H_
