//
// Created by montgomery anderson on 6/12/16.
//

#include "Launcher.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cstdio>

#include "Context.h"


int main(int argc, char **argv) {
    // Initialise glfw3
    if (!glfwInit()) {
        glfwTerminate();
    }

    // TODO Check for glfw initialisation errors

    // Initialise the OpenGL 4.1 Context
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // TODO Check for OpenGL initialisation errors

    // Instantiate the single root context (yes singleton, but underlying context is singular, hence it
    // makes sense to enforce it) - also yes, I am trying to justify this to myself also..
    Context* rootContext = Context::Instance();
    rootContext->Start();

    return 0;
}