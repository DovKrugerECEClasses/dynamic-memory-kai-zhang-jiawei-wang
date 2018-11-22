cmake_minimum_required(VERSION 3.12)
project(Bitmap)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Bitmap
        bitmap.cpp
        Color.hh)
