#include "include/Core.h"

#include "game/game-processor.h"
#include "misc/session-configuration-parser.h"

void createGameSession(const char *configuration) {
  try {
    const auto sessions = misc::SessionConfigurationParser::parseConfiguration(configuration);
    for (auto &&session : sessions) {
      game::GameProcessor::startGameSession(session);
    }
  } catch (std::exception &exception) {
    throw;
  }
}

void endGameSession(const char *session_id) {
  game::GameProcessor::stopGameSession(session_id);
}

void stopAllSessions() {
  game::GameProcessor::stopAllSessions();
}
