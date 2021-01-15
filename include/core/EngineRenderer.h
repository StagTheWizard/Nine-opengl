//
// Created by montgomery anderson on 15/12/16.
//

#ifndef NINE_RENDERER_H
#define NINE_RENDERER_H


#include <map>
#include <string>
#include <glad/glad.h>
#include <glm/vec2.hpp>
#include <glm/vec4.hpp>
#include <assimp/quaternion.h>

#include "core/libs/textlib.h"
#include "TextRenderModule.h"


using std::map;
using std::string;


class EngineRenderer {
public:
    EngineRenderer();
    ~EngineRenderer();

    int initialise();

    void renderEntity();
    void renderTerrain();
    void renderText(std::string text, Font font, glm::vec2 screenPos);
    void renderText(std::string text, Font font, glm::vec2 screenPos, glm::vec4 color);
    void renderText(std::string text, Font font, glm::vec2 screenPos, glm::vec2 scale, float rotation, glm::vec4 color);
protected:
    TextRenderModule *textRenderModule;
private:
};


#endif //NINE_RENDERER_H
