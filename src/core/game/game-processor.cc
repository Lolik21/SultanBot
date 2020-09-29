#include "game-processor.h"

#include "game-session.h"
#include "game-session-factory.h"

#include <string>

namespace game {
void GameProcessor::startGameSession(const std::shared_ptr<misc::SessionConfiguration> &session_configuration) {
  const auto session = GameSessionFactory::createGameSession(session_configuration);
  session->start();
}

void GameProcessor::stopGameSession(const std::string &session_name) {
}

void GameProcessor::stopAllSessions() {
}
}// namespace game
