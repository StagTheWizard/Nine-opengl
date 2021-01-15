//
// Created by montgomery anderson on 9/12/16.
//

#ifndef NINE_GAMESTATE_H
#define NINE_GAMESTATE_H

#endif //NINE_GAMESTATE_H


class Engine;
class EngineRenderer;


#include "Engine.h"


class State {
public:
    virtual int initialise()                = 0;
    virtual void cleanup()                  = 0;
    virtual void pause()                    = 0;
    virtual void resume()                   = 0;
    virtual void handleEvents()             = 0;
    virtual void update()                   = 0;
    virtual void draw(EngineRenderer *renderer)   = 0;


    void ChangeState(Engine *engine, State *state) {
        engine->changeState(state);
    };
protected:
    State(Engine *engine) {
        this->engine = engine;
    };


    ~State() {};
    Engine *engine;
};