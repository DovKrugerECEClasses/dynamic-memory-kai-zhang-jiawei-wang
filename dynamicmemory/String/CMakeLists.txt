cmake_minimum_required(VERSION 3.12)
project(String)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(String
        main.cc
        String.cc
        String.hh)
