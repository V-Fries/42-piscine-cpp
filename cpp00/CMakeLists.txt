cmake_minimum_required(VERSION 3.25)
project(cpp00)

set(CMAKE_CXX_STANDARD 14)

include_directories(ex01/include)
include_directories(ex02)

add_executable(cpp00
        ex00/megaphone.cpp
        ex01/include/Contact.hpp
        ex01/include/input.hpp
        ex01/include/PhoneBook.hpp
        ex01/src/classes/Contact.cpp
        ex01/src/classes/PhoneBook.cpp
        ex01/src/input.cpp
        ex01/src/main.cpp
        ex02/Account.cpp
        ex02/Account.hpp
        ex02/tests.cpp)
