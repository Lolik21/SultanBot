#ifndef SULTANBOT_CORE_GAME_GAME_PROCESSOR_H_
#define SULTANBOT_CORE_GAME_GAME_PROCESSOR_H_

#include "game-session.h"

#include <string>
#include <map>
#include "misc/session-configuration.h"

namespace game {
class GameProcessor {
 public:
  static void startGameSession(const std::shared_ptr<misc::SessionConfiguration> &session_configuration);
  static void stopGameSession(const std::string &session_name);
  static void stopAllSessions();
private:
  static std::map<std::string, std::unique_ptr<GameSession>> game_sessions_;
};
}// namespace game

#endif//SULTANBOT_CORE_GAME_GAME_PROCESSOR_H_
