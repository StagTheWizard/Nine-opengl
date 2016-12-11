//
// Created by montgomery anderson on 11/12/16.
//

#ifndef NINE_ENGINE_H
#define NINE_ENGINE_H


class State;


#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <ft2build.h>
#include FT_FREETYPE_H

#include "Camera.h"


class Engine {
public:
    FT_Library freetype;

    bool isRunning() { return running; }


    int initialise();
    void cleanup();
    void start();

    void changeState(State *state);
    void pushState(State *state);
    void popState();

    void handleEvents();
    void update();
    void draw();
    void quit();
private:
    GLFWwindow *window;
    Camera *camera;
    std::vector<State *> states;
    bool running;

};


#endif //NINE_ENGINE_H
