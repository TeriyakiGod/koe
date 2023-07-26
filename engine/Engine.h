#ifndef KOE_ENGINE_H
#define KOE_ENGINE_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include "Window.h"
#include "GameBehaviour.h"
#include <chrono>
#include <thread>
#include "ft2build.h"
#include FT_FREETYPE_H
#include "Debug.h"

namespace koe {

    class Engine {
    public:
        int OnExecute();
        void AddGameBehaviour(GameBehaviour* behaviour);
        Window& GetWindow() const;

    private:
        static bool running;
        Window* window;
        Debug* debug;
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
