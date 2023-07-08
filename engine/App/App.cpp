#include "App.h"

namespace koe {

    App::App() : running(true), window("Koe", 640, 420), renderer(window) {}

    App::~App() {}

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

        return true;
    }

    void App::OnEvent(SDL_Event* event) {
        if (event->type == SDL_QUIT) {
            running = false;
        }
        else if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_f) {
            // Toggle fullscreen when 'f' key is pressed
            window.ToggleFullscreen();
        }
    }

    void App::OnLoop() {
        // Game loop

    }

    void App::OnRender() {
        renderer.Render();
    }

    void App::OnCleanup() {
        SDL_Quit();
    }

} // namespace koe
