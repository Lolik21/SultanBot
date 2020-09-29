#ifndef CORE_GAME_GAME_SESSION_FACTORY
#define CORE_GAME_GAME_SESSION_FACTORY

#include "game-session.h"
#include "misc/session-configuration.h"

namespace game
{
class GameSessionFactory
{
public:
  static std::unique_ptr<GameSession> createGameSession(const std::shared_ptr<misc::SessionConfiguration> &session_configuration);
};
}

#endif // CORE_GAME_GAME_SESSION_FACTORY
