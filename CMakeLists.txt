cmake_minimum_required(VERSION 3.28)
project(Portfolio_Milestone)

set(CMAKE_CXX_STANDARD 17)

add_executable(Portfolio_Milestone main.cpp
        thread.h
        thread.cpp
        count.cpp
        count.h)
