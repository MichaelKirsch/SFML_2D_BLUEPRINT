#pragma once

class GameState
{
public:
    virtual void handle_events() {};
    virtual void logic() {};
    virtual void render(){};
    virtual ~GameState()= default;
};