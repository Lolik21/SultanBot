#include "include/Core.h"

#include "game/GameProcessor.h"
#include "misc/SessionConfigurationParser.h"

void createGameSession(const char *configuration) {
  const auto sessions = misc::SessionConfigurationParser::parseConfiguration(configuration);
  for (auto &&session : sessions) {
    game::GameProcessor::startGameSession(std::make_shared<misc::SessionConfiguration>(session));
  }
}

void endGameSession(const char *session_id) {
  game::GameProcessor::stopGameSession(session_id);
}

void stopAllSessions()
{
  game::GameProcessor::stopAllSessions();
}
