#include "StateMachine.h"


StateMachine::StateMachine() {
    m_Essential.m_window.init(sf::Vector2u(1200,600));
    setState(STATES::MENU);
}


void StateMachine::setState(STATES stateToSet) {
    m_GlobalGameState = stateToSet;
    switch(stateToSet)
    {
        case STATES::MENU:
            m_currentState=std::make_unique<MainMenu>();
            break;
    }
}

void StateMachine::tick() {
    m_currentState->handle_events();
    m_currentState->logic();
    m_currentState->render();
}

void StateMachine::run() {
    while(m_GlobalGameState!=STATES::EXITING)
    {
        m_currentState->handle_events();
        m_currentState->logic();
        m_currentState->render();
    }
}

