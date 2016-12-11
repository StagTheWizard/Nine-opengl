//
// Created by montgomery anderson on 11/12/16.
//

#include "core/Engine.h"
#include "core/State.h"
#include "core/Constants.h"


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

    // Initialise freetype
    FT_Error freetypeError = FT_Init_FreeType(&freetype);
    if (freetypeError) {
        fprintf(stderr, "Could not initialise freetype.");
        return EXIT_FAILURE;
    }

    window = glfwCreateWindow(constants::WINDOW_WIDTH, constants::WINDOW_HEIGHT, constants::WINDOW_TITLE, NULL, NULL);
    if (!window) glfwTerminate();

    // TODO set up key and error callbacks
//    glfwSetErrorCallback(error_prompt);
//    glfwSetKeyCallback(window, key_press);

    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
    // Set the number of screen updates before buffers are swapped (post call to glfwSwapBuffers).
    glfwSwapInterval(1);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    glClearColor(0.3f, 0.3f, 0.3f, 1);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    return EXIT_SUCCESS;
}


void Engine::cleanup() {}


void Engine::start() {

    // Start the main loop
    while (!glfwWindowShouldClose(window)) {
        this->handleEvents();
        this->update();
        this->draw();
    }

    this->cleanup();
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
    states.back()->update();
}


void Engine::quit() {
    glfwSetWindowShouldClose(window, GLFW_TRUE);
}