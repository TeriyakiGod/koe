#include "Engine.h"

namespace koe {

    bool Engine::running = true;

    auto Engine::OnExecute() -> int {
        if (!OnInit()) { return -1; }

        OnStart();
        OnLoop();
        OnCleanup();

        return 0;
    }

    auto Engine::OnInit() -> bool {
        glfwSetErrorCallback(error_callback);
        if (glfwInit() == GLFW_FALSE){ return false; }
        window = new Window("KO Engine");
        glfwSetWindowCloseCallback(window->getWindow(), close_callback);
        running = true;
        return true;
    }

    void Engine::OnStart() {
        for (GameBehaviour* behaviour : gameBehaviours) {
            behaviour->OnStart();
        }
    }

    void Engine::OnUpdate() {
        for (GameBehaviour* behaviour : gameBehaviours) {
            behaviour->OnUpdate();
        }
    }

    void Engine::OnRender() {
        window->OnRender(gameBehaviours);
    }

    void Engine::OnCleanup() {
        for (GameBehaviour* behaviour : gameBehaviours) {
            behaviour->OnCleanup();
        }
        delete window;
        glfwTerminate();
    }

    void Engine::OnLoop() {
        while (running) {
            OnUpdate();
            OnRender();
            glfwPollEvents();
        }
    }

    Window &Engine::GetWindow() const {
        return *window;
    }

    void Engine::AddGameBehaviour(GameBehaviour *behaviour) {
        gameBehaviours.push_back(behaviour);
    }

    void Engine::error_callback(int error, const char* description)
    {
        fprintf(stderr, "Error: %s\n", description);
    }

    void Engine::close_callback(GLFWwindow *window) {
        running = false;
    }


} // namespace koe
