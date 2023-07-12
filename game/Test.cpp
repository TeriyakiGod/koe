#include "../engine/GameBehaviour.h"
#include "GLFW/glfw3.h"
namespace game {
    class Test : public koe::GameBehaviour {
        double rotationAngle = 0.0;
        double rotationSpeed = 1;

        void OnStart() override{
            rotationAngle = 0.0;
        }

        void OnUpdate() override{
            rotationAngle += rotationSpeed;
        }
        void OnRender() override{
            glPushMatrix();

            // Rotate the coords
            glRotated(rotationAngle, 0, 0, 1); // Rotate around the z-axis

            glBegin(GL_TRIANGLES); // Start drawing a triangle
            // Note: We are using normalized device coordinates [-1, 1] here. So, the whole window is [-1, -1] at the bottom-left to [1, 1] at the top-right.
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex2f(0.0f, 0.5f);
            glColor3f(0.0f, 1.0f, 0.0f);
            glVertex2f(-0.5f, -0.5f);
            glColor3f(0.0f, 0.0f, 1.0f);
            glVertex2f(0.5f, -0.5f);
            glEnd(); // Triangle has been drawn

            glPopMatrix();
        }
        void OnCleanup() override{

        }
    };
}