#ifndef TEXTRENDERER_H
#define TEXTRENDERER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <map>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <ft2build.h>
#include FT_FREETYPE_H
#include "Shader.h"
#include <iostream>

namespace koe {

    class TextRenderer {
    public:
        TextRenderer(const char *fontPath, int fontSize, int screenWidth, int screenHeight);
        void RenderText(std::string text, float x, float y, float scale, glm::vec3 color);
        int GetScreenWidth() const;
        unsigned int VAO, VBO;

    private:
        struct Character {
            unsigned int TextureID;  // ID handle of the glyph texture
            glm::ivec2   Size;       // Size of glyph
            glm::ivec2   Bearing;    // Offset from baseline to left/top of glyph
            unsigned int Advance;    // Offset to advance to next glyph
        };
        std::map<char, Character> Characters;
        int screenWidth, screenHeight;
        Shader shader = Shader(R"(F:\Projects\KOE\engine\shaders\text\text.vert)", R"(F:\Projects\KOE\engine\shaders\text\text.frag)");
    };

}  // namespace koe

#endif  // TEXTRENDERER_H