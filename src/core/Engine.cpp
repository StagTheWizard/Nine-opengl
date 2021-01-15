//
// Created by montgomery anderson on 11/12/16.
//

#include <iostream>
#include "core/Engine.h"
#include "core/State.h"
#include "core/Constants.h"
#include "core/libs/filelib.h"
#include "core/EngineRenderer.h"


int Engine::initialise() {
    states = std::vector<State *>();

    // Initialise glfw3
    int glfwError = glfwInit();
    if (!glfwError) {
        glfwTerminate();
        return EXIT_FAILURE;
    }

    // Initialise the OpenGL 4.1 Context
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // TODO Check for OpenGL initialisation errors

    window = glfwCreateWindow(constants::WINDOW_WIDTH, constants::WINDOW_HEIGHT, constants::WINDOW_TITLE, NULL, NULL);
    if (!window) {
        glfwTerminate();
        return EXIT_FAILURE;
    }

    // TODO set up key and error callbacks
//    glfwSetErrorCallback(error_prompt);
//    glfwSetKeyCallback(window, key_press);

    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
    // Set the number of screen updates before buffers are swapped (post call to glfwSwapBuffers).
    glfwSwapInterval(1);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    glClearColor(0.7f, 0.7f, 0.75f, 1);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    renderer = new EngineRenderer();
    renderer->initialise();

    return EXIT_SUCCESS;
}


void Engine::cleanup() {}


void Engine::start() {

    // Start the main loop
    while (!glfwWindowShouldClose(window)) {
        try {
            this->handleEvents();
            this->update();
            this->draw();
        } catch (std::exception &e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

    }

    this->cleanup();

    glfwTerminate();
}


void Engine::changeState(State *state) {}


void Engine::pushState(State *state) {
    states.push_back(state);
}


void Engine::popState() {
    states.pop_back();
}


void Engine::handleEvents() {
    states.back()->handleEvents();
}


void Engine::update() {
    states.back()->update();
}


void Engine::draw() {
    glfwPollEvents();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    states.back()->draw(renderer);

    glfwSwapBuffers(window);
}


void Engine::quit() {
    glfwSetWindowShouldClose(window, GLFW_TRUE);
}