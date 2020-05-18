cmake_minimum_required(VERSION 3.16)
project(runnable)

set(CMAKE_CXX_STANDARD 17)

add_library(core SHARED)

add_executable(runnable main.cc)
