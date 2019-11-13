#include "Gamestate.h"


void GameState::run() {
        m_elapsed = m_Essential.m_Clock.restart().asSeconds();

        frame_cl+=m_elapsed;
        logic_cl+=m_elapsed;
        evt_cl+=m_elapsed;
        if(frame_cl>1.0/framerate)
        {

            render();
            frame_cl=0;
        }
        if(logic_cl>1.0/logicrate)
        {
            logic();
            logic_cl=0;
        }
        if(evt_cl>1.0/eventrate)
        {
            handle_events();
            evt_cl=0;
        }
}

void GameState::setFramerate(unsigned int newRate) {
    this->framerate = newRate;
}

void GameState::setLogicrate(unsigned int newRate) {
    this->logicrate = newRate;
}

void GameState::setEventrate(unsigned int newRate) {
    this->eventrate = newRate;
}
