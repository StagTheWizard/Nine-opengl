//
// Created by montgomery anderson on 6/12/16.
//

#include "Launcher.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>


int main(int argc, char **argv) {
    if (!glfwInit()) {
        glfwTerminate();
    }


    GLFWwindow *window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, NULL, NULL);
    if (!window) {
        glfwTerminate();
    }

    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);

    return 0;
}