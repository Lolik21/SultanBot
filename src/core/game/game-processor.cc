#include "game-processor.h"

#include "game-session-factory.h"
#include "game-session.h"

#include <string>

#include <Poco/Crypto/Crypto.h>

namespace game {
std::map<std::string, std::unique_ptr<GameSession>> GameProcessor::game_sessions_{};

void GameProcessor::startGameSession(const std::shared_ptr<misc::SessionConfiguration> &session_configuration) {
  Poco::Crypto::initializeCrypto();
  game_sessions_.emplace(session_configuration->name, GameSessionFactory::createGameSession(session_configuration));
  game_sessions_[session_configuration->name]->start();
}

void GameProcessor::stopGameSession(const std::string &session_name) {
  // game_sessions_[session_name].stop();
  game_sessions_.erase(session_name);
}

void GameProcessor::stopAllSessions() {
  for (auto &&game_session : game_sessions_) {
    // game_session.second.stop();
  }
  game_sessions_.clear();
}
}// namespace game
