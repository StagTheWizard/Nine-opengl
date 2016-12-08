//
// Created by montgomery anderson on 8/12/16.
//

#include "Context.h"


static Context *Context::Instance() {
    if (!instance) {
        instance = new Context();
    }
}


Context::Context() {
    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, NULL, NULL);
    if (!window) glfwTerminate();

    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);


}


Context::~Context() {}


void Context::start() {

}


void update(int value) {

}


void display() {

}


void key_press(GLFWwindow *window, int key, int scancode, int action, int mods) {

}


void error_prompt(int error, const char *description) {
    fprintf(stderr, "Error: %s\n", description);
}

