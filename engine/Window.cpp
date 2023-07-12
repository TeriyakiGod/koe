#include "Window.h"

namespace koe {

    Window::Window(const std::string& title) {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
        window = glfwCreateWindow(DEFAULT_WIDTH, DEFAULT_HEIGHT, title.c_str(), nullptr, nullptr);
        if (window == nullptr)
        {
            glfwTerminate();
            exit(EXIT_FAILURE);
        }
        glfwMakeContextCurrent(window);
        glfwSwapInterval(1);
        fullscreen = false;
    }

    Window::~Window() {
        glfwDestroyWindow(window);
    }

    auto Window::getWindow() const -> GLFWwindow* {
        return window;
    }

    void Window::OnToggleFullscreen() {
        fullscreen = !fullscreen;
        // Toggle fullscreen mode
        if (fullscreen) {
            GLFWmonitor* monitor = glfwGetPrimaryMonitor();
            const GLFWvidmode* mode = glfwGetVideoMode(monitor);
            glfwSetWindowMonitor(window, monitor, 0, 0, mode->width, mode->height, mode->refreshRate);
        } else {
            glfwSetWindowMonitor(window, nullptr, 0, 0, DEFAULT_WIDTH, DEFAULT_HEIGHT, DEFAULT_REFRESH_RATE);
        }
    }

    void Window::OnRender(std::vector<GameBehaviour *> behaviours) {
        glfwGetFramebufferSize(window, &framebufferWidth, &framebufferHeight);
        ratio = framebufferWidth / (float) framebufferHeight;
        glViewport(0, 0, framebufferWidth, framebufferHeight);
        glClear(GL_COLOR_BUFFER_BIT);
        for (GameBehaviour* behaviour : behaviours) {
            behaviour->OnRender();
        }
        glfwSwapBuffers(window);
    }

} // namespace koe
