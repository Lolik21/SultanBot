cmake_minimum_required(VERSION 3.16)
project(Core)
set (PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

find_package(Poco CONFIG REQUIRED COMPONENTS JSON NET NetSSL)

add_library(CoreLib STATIC "core.cc" "game/game-processor.cc" "misc/session-configuration.cc"
"misc/session-configuration-parser.cc" "network/auth/models/auth-configuration.cc" "network/auth/auth-service.cc"
"network/request-service.cc" "game/game-session.cc" "game/game-session-factory.cc" "network/auth/models/auth-session.cc" 
"network/secure/ecdh-key-helper.cc" "network/secure/client-data-encoder.cc" "network/secure/server-data-encoder.cc" 
"network/secure/base64-encoder.cc")

target_link_libraries(CoreLib PRIVATE Poco::JSON Poco::Net Poco::NetSSL)
target_include_directories(CoreLib PRIVATE ./)
