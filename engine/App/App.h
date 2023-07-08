#ifndef APP_H
#define APP_H

#include <SDL.h>
#include <string>
#include "../Window/Window.h"
#include "../Renderer/Renderer.h"

namespace koe {

    class App {
    public:
        App();
        ~App();

        int OnExecute();

    private:
        bool running;
        Window window;
        Renderer renderer;

        bool OnInit();
        void OnEvent(SDL_Event* event);
        void OnLoop();
        void OnRender();
        void OnCleanup();
    };

} // namespace koe

#endif // APP_H
