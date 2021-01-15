//
// Created by montgomery anderson on 6/12/16.
//

#include <iostream>
#include "Launcher.h"
#include "core/Engine.h"
#include "core/IntroState.h"
#include "core/Constants.h"

using namespace std;


int main(int argc, char **argv) {
    std::cout << "Launching " << constants::WINDOW_TITLE << std::endl;
    Engine *engine = new Engine();
    if(engine->initialise()) {
        std::cout << "The Nine engine failed to initialise, closing now." << std::endl;
        return EXIT_FAILURE;
    }

    engine->pushState(new IntroState(engine));
    engine->start();

    return EXIT_SUCCESS;
}