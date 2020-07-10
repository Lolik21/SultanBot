cmake_minimum_required(VERSION 3.16)
project(Core)
set (PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

find_package(Poco CONFIG REQUIRED COMPONENTS Json)

add_library(CoreLib STATIC Core.cc game/GameProcessor.cc misc/SessionConfiguration.cc misc/SessionConfigurationParser.cc
network/auth/AuthConfiguration.cc network/auth/AuthService.cc network/RequestService.cc game/GameSession.cc 
game/GameSessionFactory.cc)
target_link_libraries(CoreLib PRIVATE Poco::JSON)
target_include_directories(CoreLib PRIVATE ./)
