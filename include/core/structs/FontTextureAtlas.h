//
// Created by montgomery anderson on 19/12/16.
//

#ifndef NINE_FONTTEXTUREATLAS_H
#define NINE_FONTTEXTUREATLAS_H

#include <glad/glad.h>
#include <ft2build.h>
#include FT_FREETYPE_H

#include "FontChar.h"


struct FontTextureAtlas {
//    GLuint texture;
    GLuint uniformTextureLocation;

    int width;
    int height;

    FontChar characters[128];

    FontTextureAtlas(FT_Face face, int h);
    ~FontTextureAtlas();
};

#endif //NINE_FONTTEXTUREATLAS_H
