#include <iostream>
#include "App.h"

namespace koe {

    App::App() {
        running = true;
    }

    int App::OnExecute() {
        if (!OnInit()) {
            printf("Error initializing application: %s\n", SDL_GetError());
            return -1;
        }
        SDL_Event Event;

        while(running) {
            while(SDL_PollEvent(&Event)) {
                OnEvent(&Event);
            }

            OnLoop();
            OnRender();
        }

        OnCleanup();

        return 0;
    }

    bool App::OnInit() {
        rendererFlags = SDL_RENDERER_ACCELERATED;
        windowFlags = 0;

        if(SDL_Init(SDL_INIT_VIDEO) < 0) {
            return false;
        }

        window = SDL_CreateWindow(
                "Koe",
                SDL_WINDOWPOS_UNDEFINED,
                SDL_WINDOWPOS_UNDEFINED,
                SCREEN_WIDTH,
                SCREEN_HEIGHT,
                windowFlags
                );
        if(!window) return false;

        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

        renderer = SDL_CreateRenderer(window, -1, rendererFlags);
        if(!renderer) return false;

        return true;
    }

    void App::OnEvent(SDL_Event *event) {
        if(event->type == SDL_QUIT) {
            running = false;
        }
    }

    void App::OnLoop() {

    }

    void App::OnRender() {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

    void App::OnCleanup() {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
}