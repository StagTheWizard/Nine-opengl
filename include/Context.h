//
// Created by montgomery anderson on 8/12/16.
//

#ifndef NINE_CONTEXT_H
#define NINE_CONTEXT_H


/*
 * The root context of the game.
 */
class Context {
public:
    ~Context();

    static Context *Instance();

    void start();

protected:


private:
    Context();

    static Context *instance;

    GLFWwindow *window;
};


void update(int value);

void display();

void key_press(GLFWwindow *window, int key, int scancode, int action, int mods);

void error_prompt(int error, const char *description);

#endif //NINE_CONTEXT_H
