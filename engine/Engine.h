#ifndef KOE_ENGINE_H
#define KOE_ENGINE_H

#include <vector>
#include "Window.h"
#include "GameBehaviour.h"
#include "GLFW/glfw3.h"
#include <chrono>
#include <thread>


namespace koe {

    class Engine {
    public:
        int OnExecute();
        void AddGameBehaviour(GameBehaviour* behaviour);
        Window& GetWindow() const;

    private:
        static bool running;
        Window* window;
        std::vector<GameBehaviour*> gameBehaviours;

        bool OnInit();
        void OnStart();
        void OnUpdate();
        void OnRender();
        void OnCleanup();
        void OnLoop();

        static void error_callback(int error, const char* description);
        static void close_callback(GLFWwindow* window);
    };

} // namespace koe

#endif // KOE_ENGINE_H
