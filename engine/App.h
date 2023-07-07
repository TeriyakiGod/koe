#ifndef KOE_APP_H
#define KOE_APP_H

#include "SDL.h"
#include "SDL_video.h"
#include "defs.h"

namespace koe {

    class App {
    private:
        bool running;
        int windowFlags{}, rendererFlags{};
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
    };

}

#endif
