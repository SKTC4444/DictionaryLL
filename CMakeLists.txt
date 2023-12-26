cmake_minimum_required(VERSION 3.26)
project(DictionaryLL)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(DictionaryLL
        linkedlist.cpp
        linkedlist.h
        main.cpp
        node.cpp
        node.h
        test.cpp
        test.h)
