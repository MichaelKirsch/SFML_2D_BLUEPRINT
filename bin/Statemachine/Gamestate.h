#pragma once

#include "EssentialWindow.h"

class GameState {
public:
    GameState(EssentialWindow& window) : m_Essential(window) {
        framerate = 60; logicrate =30;eventrate =30;
    };
    EssentialWindow* getGamestateEssential(){ return &m_Essential;};
    void setFramerate(unsigned int newRate);
    void setLogicrate(unsigned int newRate);
    void setEventrate(unsigned int newRate);
    float getElapsedTime(){ return m_elapsed;};
    void run();

    virtual void handle_events() {
        printf("base events");
    };

    virtual void logic() {
        printf("base logic");
    };

    virtual void render() {
        printf("base render");
    };

    virtual ~GameState() = default;

private:
    EssentialWindow& m_Essential;
    float m_elapsed;
    float frame_cl;
    float logic_cl;
    float evt_cl;
    unsigned int framerate, logicrate,eventrate;
};

