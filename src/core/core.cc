#include "include/Core.h"

#include "game/GameProcessor.h"
#include "misc/SessionConfigurationParser.h"

void createGameSession(const char *configuration) {
  try {
    const auto sessions = misc::SessionConfigurationParser::parseConfiguration(configuration);
    for (auto &&session : sessions) {
      game::GameProcessor::startGameSession(session);
    }
  } catch (std::exception &exception) {
    std::cout << "The Error occured when creating a game session:\n";
    std::cout << exception.what() << std::endl;
  }
}

void endGameSession(const char *session_id) {
  game::GameProcessor::stopGameSession(session_id);
}

void stopAllSessions() {
  game::GameProcessor::stopAllSessions();
}
