//
// Created by montgomery anderson on 12/12/16.
//


#include "core/IntroState.h"
#include "core/EngineRenderer.h"


IntroState::IntroState(Engine *engine) : State(engine) {}


IntroState::~IntroState() {}


int IntroState::initialise() {
    return EXIT_SUCCESS;
}


void IntroState::cleanup() {}


void IntroState::pause() {}


void IntroState::resume() {}


void IntroState::handleEvents() {}


void IntroState::update() {}


void IntroState::draw(EngineRenderer *renderer) {
    renderer->renderText(INTRO_TEXT, Font::DEFAULT, glm::vec2(20, 20));
}


