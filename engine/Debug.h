#ifndef DEBUG_H
#define DEBUG_H

#include <chrono>
#include "GameBehaviour.h"
#include "textrenderer.h"

namespace koe {

    class Debug : public GameBehaviour {
    public:
        Debug(TextRenderer& textRenderer);

        void OnStart() override;
        void OnUpdate() override;
        void OnRender() override;
        void OnCleanup() override;

    private:
        TextRenderer& textRenderer;
        std::chrono::steady_clock::time_point startTime;
        int frameCount;
        float fps;
    };

} // namespace koe

#endif // DEBUG_H
