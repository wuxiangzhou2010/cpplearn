cmake_minimum_required(VERSION 3.13)
project(coordinate)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(coordinate
        coordinate.cpp
        coordinate.h
        main.cpp)
