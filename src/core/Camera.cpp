//
// Created by montgomery anderson on 9/12/16.
//

#include "core/Camera.h"
#include "core/Constants.h"
#include <glm/glm.hpp>


using namespace constants;


Camera::Camera() {
    screenDimensions = glm::vec2(WINDOW_WIDTH, WINDOW_HEIGHT);
}


void Camera::key_press(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_W) move_forward();
    if (key == GLFW_KEY_A) strafe_left();
    if (key == GLFW_KEY_S) move_backwards();
    if (key == GLFW_KEY_D) strafe_right();
    if (key == GLFW_KEY_SPACE) move_up();
    if (key == GLFW_KEY_LEFT_SHIFT) move_down();
}


Camera::Camera(glm::vec3 pos, glm::vec3 upDir, glm::vec3 viewDir) : Camera() {
    this->pos = pos;
    this->upDir = upDir;
    this->viewDir = viewDir;
    viewPt = pos + viewDir;
}


void Camera::move_forward() {
    pos += viewDir * DIRECTIONAL_SPEED;
    viewPt = pos + viewDir;
}


void Camera::move_backwards() {
    pos -= viewDir * DIRECTIONAL_SPEED;
    viewPt = pos + viewDir;
}


void Camera::strafe_left() {
    pos -= glm::cross(viewDir, upDir) * LATERAL_SPEED;
    viewPt = pos + viewDir;
}


void Camera::strafe_right() {
    pos += glm::cross(viewDir, upDir) * LATERAL_SPEED;
    viewPt = pos + viewDir;
}


void Camera::move_up() {
    pos += upDir * VERTICAL_SPEED;
    viewPt = pos + viewDir;
}


void Camera::move_down() {
    pos -= upDir * VERTICAL_SPEED;
    viewPt = pos + viewDir;
}
