#pragma once

#include "EssentialWindow.h"

class GameState {
public:
    GameState(EssentialWindow& window);
    EssentialWindow* getGamestateEssential(){ return &m_Essential;};
    float getRuntimeOfState(){ return state_timer;};
    float getStartingTimeOfState(){ return time_at_start;};
    float getRenderingTime(bool asFps);
    float getLogicTime(bool asFps);
    float getEventTime(bool asFps);
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
    float m_elapsed,timeNeededForRender,timeNeededForLogic,timeNeededForEvents;
    float frame_cl,logic_cl,evt_cl,time_at_start,state_timer;
};

