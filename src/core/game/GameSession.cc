#include "GameSession.h"
#include <utility>

namespace game
{
GameSession::GameSession(
    std::shared_ptr<misc::SessionConfiguration> session_configuration,
    std::shared_ptr<network::auth::AuthService> auth_service):
      session_configuration_(std::move(session_configuration)),
      auth_service_(std::move(auth_service))
{
}

void GameSession::start()
{
  std::cout << "Starting game session. DeviceID: " << session_configuration_->device_id << "\n";
  auth_service_->authenticate();
}
}
