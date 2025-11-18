cmake_minimum_required(VERSION 4.0)
project(Task1)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_C_FLAGS "-Wall -Wextra")

add_executable(Task1 main.cpp
        Team.h
        Tournament.h)
