//
// Created by montgomery anderson on 15/12/16.
//

#include "core/EngineRenderer.h"


EngineRenderer::EngineRenderer() {
    textRenderModule = new TextRenderModule();
}


EngineRenderer::~EngineRenderer() {}


int EngineRenderer::initialise() {
    if (textRenderModule->initialise()) return EXIT_FAILURE;

    return EXIT_SUCCESS;
}


void EngineRenderer::renderEntity() {}


void EngineRenderer::renderTerrain() {}


void EngineRenderer::renderText(std::string text, Font font, glm::vec2 screenPos) {
    renderText(text, font, screenPos, glm::vec2(1, 1), 0, glm::vec4(1, 1, 1, 1));
}


void EngineRenderer::renderText(std::string text, Font font, glm::vec2 screenPos, glm::vec4 color) {
    renderText(text, font, screenPos, glm::vec2(1, 1), 0, color);
}


void EngineRenderer::renderText(std::string text, Font font, glm::vec2 screenPos, glm::vec2 scale, float rotation,
                          glm::vec4 color) {
//    glUseProgram(textShader);
//    glPushMatrix();
//        glLoadIdentity();
//        glColor3f(color.x, color.y, color.z);
//        textlib::print(fontDataMap[font], 320, 200, text.c_str());
//    glPopMatrix();
    textRenderModule->print(text, font, 12, screenPos.x, screenPos.y);
}
