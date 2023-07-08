#include "Renderer.h"

namespace koe {

    Renderer::Renderer(Window& window) : renderer(nullptr) {
        renderer = SDL_CreateRenderer(window.GetSDLWindow(), -1, SDL_RENDERER_ACCELERATED);
    }

    Renderer::~Renderer() {
        if (renderer) {
            SDL_DestroyRenderer(renderer);
            renderer = nullptr;
        }
    }

    SDL_Renderer* Renderer::GetSDLRenderer() const {
        return renderer;
    }

    void Renderer::Render() {
        SDL_RenderClear(renderer);

        // Perform rendering operations here
        // ...

        SDL_RenderPresent(renderer);
    }

} // namespace koe
