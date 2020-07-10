#include "GameSessionFactory.h"

namespace game
{
std::unique_ptr<GameSession> GameSessionFactory::createGameSession(
    const std::shared_ptr<misc::SessionConfiguration> &session_configuration)
{
  const auto auth_configuration = std::make_shared<network::auth::AuthConfiguration>(session_configuration);
  const auto auth_service = std::make_shared<network::auth::AuthService>(auth_configuration);
  return std::make_unique<GameSession>(session_configuration, auth_service);
}
}
