#ifndef RENDERER_H
#define RENDERER_H

#include <SDL.h>
#include "../Window/Window.h"

namespace koe {

    class Renderer {
    public:
        Renderer(Window& window);
        ~Renderer();

        SDL_Renderer* GetSDLRenderer() const;
        void Render();

    private:
        SDL_Renderer* renderer;
    };

} // namespace koe

#endif // RENDERER_H
