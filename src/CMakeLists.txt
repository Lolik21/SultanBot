cmake_minimum_required(VERSION 3.16)

project(SultanBot)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/../build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

enable_testing()
add_subdirectory(core)
add_subdirectory(test)
add_executable(SultanBot main.cpp)
target_link_libraries(SultanBot CoreLib)

configure_file(config.json ${CMAKE_BINARY_DIR} COPYONLY)
