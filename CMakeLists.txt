cmake_minimum_required(VERSION 3.25)
project(KOE)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -lmingw32")
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

include_directories(${PROJECT_SOURCE_DIR}/include/SDL2)
link_directories(${PROJECT_SOURCE_DIR}/lib)

add_executable(KOE main.cpp engine/App.cpp engine/App.h engine/defs.h)

target_link_libraries(KOE mingw32 SDL2main SDL2)