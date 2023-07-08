#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include <string>

namespace koe {

    class Window {
    public:
        Window(const std::string& title, int width, int height);
        ~Window();

        SDL_Window* GetSDLWindow() const;

        void ToggleFullscreen();

    private:
        SDL_Window* window;
        bool fullscreen;
    };

} // namespace koe

#endif // WINDOW_H
