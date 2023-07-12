#ifndef WINDOW_H
#define WINDOW_H

#include "GLFW/glfw3.h"
#include "GameBehaviour.h"
#include <string>
#include <vector>

namespace koe {

    class Window {
    public:
        Window(const std::string& title);
        ~Window();

        GLFWwindow * getWindow() const;

        void OnToggleFullscreen();
        void OnRender(std::vector<GameBehaviour*> behaviours);

    private:
        GLFWwindow* window;
        bool fullscreen;

        int framebufferWidth;
        int framebufferHeight;
        float ratio;

        const int DEFAULT_WIDTH = 1280;
        const int DEFAULT_HEIGHT = 720;
        const int DEFAULT_REFRESH_RATE = 60;
    };

} // namespace koe

#endif // WINDOW_H
