#include "Debug.h"
#include <iostream>

namespace koe {

    Debug::Debug(TextRenderer& textRenderer) : textRenderer(textRenderer), frameCount(0), fps(0.0f) {}

    void Debug::OnStart() {
        startTime = std::chrono::steady_clock::now();
    }

    void Debug::OnUpdate() {
        frameCount++;

        // Calculate FPS
        auto currentTime = std::chrono::steady_clock::now();
        auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - startTime).count() / 1000.0;
        if (elapsedTime >= 1.0) {
            fps = frameCount / elapsedTime;
            frameCount = 0;
            startTime = currentTime;
        }
    }

    void Debug::OnRender() {
        // Display FPS in the upper right corner
        std::string fpsString = "FPS: " + std::to_string(fps);
        float x = textRenderer.GetScreenWidth() - 100.0f;
        float y = 20.0f;
        float scale = 0.5f;
        //set color to white
        glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f);
        textRenderer.RenderText(fpsString, x, y, scale, color);
    }

    void Debug::OnCleanup() {}

} // namespace koe
