#include "Window.h"

namespace koe {

    Window::Window(const std::string& title, int width, int height) : window(nullptr), fullscreen(false) {
        window = SDL_CreateWindow(
                title.c_str(),
                SDL_WINDOWPOS_UNDEFINED,
                SDL_WINDOWPOS_UNDEFINED,
                width,
                height,
                0
        );
    }

    Window::~Window() {
        if (window) {
            SDL_DestroyWindow(window);
            window = nullptr;
        }
    }

    SDL_Window* Window::GetSDLWindow() const {
        return window;
    }

    void Window::ToggleFullscreen() {
        fullscreen = !fullscreen;

        // Toggle fullscreen mode
        if (fullscreen) {
            SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
        } else {
            SDL_SetWindowFullscreen(window, 0);
        }
    }

} // namespace koe
