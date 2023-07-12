#ifndef DEBUG_H_
#define DEBUG_H_

#include "GameBehaviour.h"
#include "GLFW/glfw3.h"

class Debug : public koe::GameBehaviour {
private:
    int frameCount;
    double timeCount;
    double fps;
public:
    Debug();

    void OnStart() override;
    void OnUpdate() override;
    void OnRender() override;
};

#endif // DEBUG_H_