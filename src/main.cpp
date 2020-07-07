#include "core/include/Core.h"
#include <fstream>
#include <sstream>

int main() {
  std::stringstream string_steam;
  const std::ifstream file_stream("config.json");
  string_steam << file_stream.rdbuf();
  createGameSession(string_steam.str().c_str());
  return 0;
}
