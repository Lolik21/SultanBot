#ifndef CORE_GAME_GAME_SESSION
#define CORE_GAME_GAME_SESSION

#include "misc/SessionConfiguration.h"
#include "network/auth/AuthService.h"
#include <memory>

namespace game {
class GameSession {
 public:
  GameSession(std::shared_ptr<misc::SessionConfiguration> session_configuration,
      std::shared_ptr<network::auth::AuthService> auth_service);
  void start();

 private:
  std::shared_ptr<misc::SessionConfiguration> session_configuration_{};
  std::shared_ptr<network::auth::AuthService> auth_service_{};
};
}// namespace game

#endif// CORE_GAME_GAME_SESSION
