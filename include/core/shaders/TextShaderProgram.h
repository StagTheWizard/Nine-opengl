//
// Created by montgomery anderson on 20/12/16.
//

#ifndef NINE_TEXTSHADERPROGRAM_H
#define NINE_TEXTSHADERPROGRAM_H

#include <glm/vec3.hpp>
#include "ShaderProgram.h"

class TextShaderProgram : public ShaderProgram {
public:
    GLuint uniformInputColor;
    GLuint uniformTextureMap;


    TextShaderProgram();
    ~TextShaderProgram();

    void bindUniforms();
    void updateUniforms(glm::vec3 color);
protected:
    virtual void initialiseShaders() override;
private:
};

#endif //NINE_TEXTSHADERPROGRAM_H
