cmake_minimum_required(VERSION 3.25)
project(KOE)

include_directories(${PROJECT_SOURCE_DIR}/external/include)
link_directories(${PROJECT_SOURCE_DIR}/external/lib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -lmingw32")
set(CMAKE_EXE_LINKER_FLAGS "-mconsole -static-libgcc -static-libstdc++")

# OpenGL
find_package(OpenGL REQUIRED)

add_executable(
        KOE
        main.cpp
        engine/Engine.cpp
        engine/Engine.h
        engine/Window.cpp
        engine/Window.h
        engine/GameObject.cpp
        engine/GameObject.h
        engine/Level.cpp
        engine/Level.h
        engine/GameBehaviour.h
        game/Test.cpp
        engine/Debug.cpp
        engine/Debug.h
)

target_link_libraries(KOE opengl32 glfw3dll freetype)