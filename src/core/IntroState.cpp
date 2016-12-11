//
// Created by montgomery anderson on 12/12/16.
//


#include "core/IntroState.h"
#include <freetype/freetype.h>


IntroState::IntroState(Engine *engine) : State(engine) {}


IntroState::~IntroState() {}


int IntroState::initialise() {
    // Initialise the freetype font.
    if (FT_New_Face(engine->freetype, "FreeSans.ttf", 0, &face)) {
        fprintf(stderr, "Could not load font.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}


void IntroState::cleanup() {}


void IntroState::pause() {}


void IntroState::resume() {}


void IntroState::handleEvents() {}


void IntroState::update() {}


void IntroState::draw() {

}


