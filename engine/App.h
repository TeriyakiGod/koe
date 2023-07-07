#ifndef KOE_APP_H
#define KOE_APP_H

#include "SDL.h"
#include "SDL_video.h"

namespace koe {

    class App {
    private:
        bool running;
        bool fullscreen{};
        SDL_Window *window{};
        SDL_Renderer *renderer{};
    public:
        App();
        int OnExecute();
        bool OnInit();
        void OnEvent(SDL_Event *event);
        void OnLoop();
        void OnRender();
        void OnCleanup();
        void ToggleFullscreen();
    };

}

#endif
