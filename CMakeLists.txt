cmake_minimum_required(VERSION 3.3)
project(Poly)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp poly.cpp poly.h)
add_executable(Poly ${SOURCE_FILES})