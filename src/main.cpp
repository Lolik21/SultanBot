#include "core/include/core.h"
#include <fstream>
#include <iostream>
#include <sstream>

int main() {
  std::stringstream string_steam;
  const std::ifstream file_stream("config.json");
  string_steam << file_stream.rdbuf();
  try {
    createGameSession(string_steam.str().c_str());
  } catch (...) {
    std::cout << "Unexpected error occured. Application will exit...";
    std::cin.get();
  }
  return 0;
}
