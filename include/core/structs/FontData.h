//
// Created by montgomery anderson on 16/12/16.
//

#ifndef NINE_FONTDATA_H
#define NINE_FONTDATA_H

#include <glad/glad.h>


struct FontData {
    float height;
    GLuint *textures;
    GLuint listBase;

    void initialise(const char *fname, unsigned int height);
    void clean();
};


#endif //NINE_FONTDATA_H
