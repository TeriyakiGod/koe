#include "Debug.h"
#include <iostream>
#include <ctime>

Debug::Debug() : frameCount(0), timeCount(0), fps(0) {}

void Debug::OnStart() {
    frameCount = 0;
    timeCount = 0;
}

void Debug::OnUpdate() {
    frameCount++;

    double elapsed = glfwGetTime() - timeCount;
    timeCount = glfwGetTime();

    if (elapsed > 0)
        fps = (double)frameCount / elapsed;

}

void Debug::OnRender() {
    // Nothing for now
}