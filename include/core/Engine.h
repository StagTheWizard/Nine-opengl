//
// Created by montgomery anderson on 11/12/16.
//

#ifndef NINE_ENGINE_H
#define NINE_ENGINE_H


class State;
class EngineRenderer;


#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Camera.h"


class Engine {
public:
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
    EngineRenderer *renderer;

    std::vector<State *> states;

    bool running;
};


#endif //NINE_ENGINE_H
