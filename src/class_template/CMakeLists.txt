cmake_minimum_required(VERSION 3.13)
project(class_template)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(class_template
        class_template.cpp
        class_template.h)
