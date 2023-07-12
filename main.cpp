#include "engine/Engine.h"
#include "game/Test.cpp"

auto WinMain(int argc, char* argv[]) -> int {
    koe::Engine engine;
    game::Test test;
    engine.AddGameBehaviour(&test);
    return engine.OnExecute();
}