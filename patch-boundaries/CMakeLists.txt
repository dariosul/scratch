cmake_minimum_required(VERSION 2.8)
project(patchboundaries)

set(CMAKE_CXX_FLAGS "-std=c++11 -g -Wall -Werror")

add_executable(patchboundaries
    src/patch.h src/patch.cpp
    src/main.cpp
)
