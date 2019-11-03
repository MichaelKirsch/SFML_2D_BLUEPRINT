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
            m_currentState=std::make_unique<MainMenu>(&m_Essential);
            break;
    }
}

void StateMachine::run() {
    while(m_GlobalGameState!=STATES::EXITING)
    {
        m_currentState->run();
    }
}

