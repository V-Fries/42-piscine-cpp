cmake_minimum_required(VERSION 3.26)
project(cpp02)

set(CMAKE_CXX_STANDARD 98)

include_directories(ex00)

add_executable(ex00
        ex00/Fixed.cpp
        ex00/Fixed.h
        ex00/main.cpp)

include_directories(ex01)

add_executable(ex01 ex01/main.cpp
        ex01/Fixed.h
        ex01/Fixed.cpp)
