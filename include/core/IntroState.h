//
// Created by montgomery anderson on 12/12/16.
//

#ifndef NINE_INTROSTATE_H
#define NINE_INTROSTATE_H


#include "State.h"

#include <ft2build.h>
#include <core/libs/textlib.h>
#include FT_FREETYPE_H


class IntroState : public State {
public:
    const char* INTRO_TEXT = "Nine Intro Text";
    textlib::FontData font;

    IntroState(Engine *engine);
    ~IntroState();

    int initialise();
    void cleanup();

    void pause();
    void resume();

    void handleEvents();
    void update();
    void draw(EngineRenderer *renderer);
protected:
private:
    FT_Face face;
};


#endif //NINE_INTROSTATE_H
