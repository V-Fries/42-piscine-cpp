cmake_minimum_required(VERSION 3.22)
project(ex02)

set(CMAKE_CXX_STANDARD 98)

include_directories(.)

add_executable(ex02
		main.cpp
		PmergeMe.cpp
		PmergeMe.hpp)
