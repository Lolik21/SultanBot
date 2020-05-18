cmake_minimum_required(VERSION 3.16)
project(core VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)

add_library(core SHARED library.cc library.h)