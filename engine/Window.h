#ifndef WINDOW_H
#define WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "GameBehaviour.h"
#include <string>
#include <vector>
#include "TextRenderer.h"

namespace koe {

    class Window {
    public:
        Window(const std::string& title);
        ~Window();

        GLFWwindow * getWindow() const;
        TextRenderer* getTextRenderer() const;

        void OnToggleFullscreen();
        void OnRender(std::vector<GameBehaviour*> behaviours);

    private:
        GLFWwindow* window;
        TextRenderer* textRenderer;
        static bool fullscreen;

        int framebufferWidth;
        int framebufferHeight;

        const int DEFAULT_WIDTH = 1280;
        const int DEFAULT_HEIGHT = 720;
        const int DEFAULT_REFRESH_RATE = 60;
    };

} // namespace koe

#endif // WINDOW_H
