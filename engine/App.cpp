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

        const int loopDelay = 1000 / 20;  // Delay for 20fps (in milliseconds)
        const int renderDelay = 1000 / 60;  // Delay for 60fps (in milliseconds)

        Uint32 loopTimer = SDL_GetTicks();  // Timer for loop execution
        Uint32 renderTimer = SDL_GetTicks();  // Timer for rendering

        while (running) {
            while (SDL_PollEvent(&Event)) {
                OnEvent(&Event);
            }

            // Run OnLoop() at 20fps
            Uint32 currentTicks = SDL_GetTicks();
            if (currentTicks - loopTimer >= loopDelay) {
                OnLoop();
                loopTimer = currentTicks;
            }
            else {
                SDL_Delay(loopDelay - (currentTicks - loopTimer));
            }

            // Run OnRender() at 60fps
            currentTicks = SDL_GetTicks();
            if (currentTicks - renderTimer >= renderDelay) {
                OnRender();
                renderTimer = currentTicks;
            }
            else {
                SDL_Delay(renderDelay - (currentTicks - renderTimer));
            }
        }

        OnCleanup();

        return 0;
    }

    bool App::OnInit() {
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            return false;
        }

        window = SDL_CreateWindow(
                "Koe",
                SDL_WINDOWPOS_UNDEFINED,
                SDL_WINDOWPOS_UNDEFINED,
                640,
                420,
                0
        );
        if (!window) return false;

        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if (!renderer) return false;

        return true;
    }

    void App::OnEvent(SDL_Event* event) {
        if (event->type == SDL_QUIT) {
            running = false;
        }
        else if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_f) {
            // Toggle fullscreen when 'f' key is pressed
            ToggleFullscreen();
        }
    }

    void App::ToggleFullscreen() {
        fullscreen = !(SDL_GetWindowFlags(window) & SDL_WINDOW_FULLSCREEN_DESKTOP);

        // Toggle fullscreen mode
        if (!fullscreen) {
            SDL_SetWindowFullscreen(window, 0);  // Switch to windowed mode
        }
        else {
            SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);  // Switch to fullscreen mode
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