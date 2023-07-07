cmake_minimum_required(VERSION 3.25)
project(KOE)

set(CMAKE_CXX_STANDARD 17)

add_executable(KOE main.cpp engine/App.cpp engine/App.h)