//
// Created by montgomery anderson on 13/12/16.
//

#ifndef NINE_TEXTLIB_H
#define NINE_TEXTLIB_H


#include <vector>
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


namespace textlib {

    using std::vector;
    using std::string;


    struct FontData {
        float height;
        GLuint *textures;
        GLuint listBase;

        void initialise(const char* fname, unsigned int height);
        void clean();
    };


    void print(const FontData &ftFont, float x, float y, const char* fmt, ...);
}

#endif //NINE_TEXTLIB_H
