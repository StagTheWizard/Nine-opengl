//
// Created by montgomery anderson on 16/12/16.
//

#ifndef NINE_TEXTRENDERMODULE_H
#define NINE_TEXTRENDERMODULE_H


#include <glad/glad.h>
#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_GLYPH_H
#include <string>
#include <map>
#include <core/structs/FontTextureAtlas.h>
#include <core/shaders/TextShaderProgram.h>

#include "core/structs/FontData.h"
#include "core/structs/FontTextureAtlas.h"


enum Font {
    DEFAULT,
    MENLO
};


/**
 * The TextRenderModule is simply a module of the EngineRenderer responsible for all render code
 * relevant for text rendering.
 */
class TextRenderModule {
public:
    TextRenderModule();
    ~TextRenderModule();

    int initialise();
    void print(std::string text, Font font, int size, float x, float y);
protected:
private:
    TextShaderProgram *textShader;

    GLuint vao;
    GLuint vertexBuffer;
    GLuint uvBuffer;

    FontTextureAtlas* menloAtlas_12pt;

    std::map<Font, std::string> fontLocMap = {
            {Font::DEFAULT, "assets/fonts/Menlo-Regular.ttf"},
            {Font::MENLO, "assets/fonts/Menlo-Regular.ttf"}
    };

    int initialiseShaders();
    int initialiseFonts();
    int initialiseFont(Font font);
};

#endif //NINE_TEXTRENDERMODULE_H
