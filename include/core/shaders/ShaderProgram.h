//
// Created by montgomery anderson on 19/12/16.
//

#ifndef NINE_SHADERPROGRAM_H
#define NINE_SHADERPROGRAM_H

#include <glad/glad.h>
#include <string>


class ShaderProgram {
public:
    ShaderProgram();

    void initialise();
    void activate();
protected:
    GLuint program;

    GLuint vertShader;
    GLuint tessCtrlShader;
    GLuint tessEvalShader;
    GLuint geomShader;
    GLuint fragShader;

    bool uniformsBound = false;

    virtual void initialiseShaders() = 0;
    void assembleProgram();

    GLuint loadShader(GLenum shaderType, std::string filename);


};

#endif //NINE_SHADERPROGRAM_H
