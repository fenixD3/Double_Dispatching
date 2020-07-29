cmake_minimum_required(VERSION 3.16)
project(DD)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(DD
        collide.cpp
        collide.h
        game_object.h
        geo2d.cpp
        geo2d.h
        test_runner.h)
