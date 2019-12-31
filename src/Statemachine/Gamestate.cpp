#include "Gamestate.h"


void GameState::run() {
        m_elapsed = m_Essential.m_Clock.restart().asSeconds();
        state_timer+=m_elapsed;
        frame_cl+=m_elapsed;
        logic_cl+=m_elapsed;
        evt_cl+=m_elapsed;

    if(!init)
    {
        logic();
        handle_events();
        render();
        init= true;
    }

    if(logic_cl>1.0/m_Essential.Updaterate)
    {
        logic();
        timeNeededForLogic = m_Essential.m_Clock.getElapsedTime().asSeconds();
        logic_cl=0;
    }

    if(evt_cl>1.0/m_Essential.Eventrate)
    {
        handle_events();
        GameState::handle_events();
        timeNeededForEvents = m_Essential.m_Clock.getElapsedTime().asSeconds();
        evt_cl=0;
    }

    if(frame_cl>1.0/m_Essential.Framerate)
    {
        render();
        timeNeededForRender = m_Essential.m_Clock.getElapsedTime().asSeconds();
        frame_cl=0;
    }
        totalframetime = timeNeededForEvents+timeNeededForRender+timeNeededForLogic;
    }

GameState::GameState(EssentialWindow &window) : m_Essential(window),m_Gui(window) {
    state_timer = m_Essential.m_Clock.getElapsedTime().asSeconds();
    time_at_start = m_Essential.m_Clock.getElapsedTime().asSeconds();
}

float GameState::getEventTime(bool asFps) {
    return asFps ? 1.0f/timeNeededForLogic : timeNeededForLogic;
}

float GameState::getLogicTime(bool asFps) {
    return asFps ? 1.0f/timeNeededForLogic : timeNeededForLogic;
}

float GameState::getRenderingTime(bool asFps) {
    return asFps ? 1.0f/timeNeededForRender : timeNeededForRender;
}


