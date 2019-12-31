#pragma once

#include "EssentialWindow.h"
#include "GuiManager.h"
class GameState {
public:
    GameState(EssentialWindow& window);
    gui::Manager m_Gui;
    EssentialWindow* getGamestateEssential(){ return &m_Essential;};
    float getRuntimeOfState(){ return state_timer;};
    float getStartingTimeOfState(){ return time_at_start;};
    float getRenderingTime(bool asFps);
    float getLogicTime(bool asFps);
    float getEventTime(bool asFps);
    float getTotalFrameTime(){ return totalframetime;};
    void run();

    virtual void handle_events() {
        m_Gui.update();
        sf::Event m_Event;
        while (getGamestateEssential()->m_Window.pollEvent(m_Event))
        {
            if (m_Event.type == sf::Event::Closed )
            {
                GameState::getGamestateEssential()->nextState = STATES::CLOSING;
            }
        }
    };

    virtual void logic() {
    };

    virtual void render() {
        m_Essential.m_Window.clear();
        m_Gui.draw();
    };

    virtual ~GameState() = default;

private:
    EssentialWindow& m_Essential;
    bool init = false;
    float m_elapsed,timeNeededForRender,timeNeededForLogic,timeNeededForEvents;
    float frame_cl,logic_cl,evt_cl,time_at_start,state_timer,totalframetime;
};

