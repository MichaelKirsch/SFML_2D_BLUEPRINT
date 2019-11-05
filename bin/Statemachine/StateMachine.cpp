#include "StateMachine.h"


StateMachine::StateMachine() {
    m_Essential.m_Window.create(sf::VideoMode(1000,1000),"Hello");
    m_Essential.m_Window.clear(sf::Color::Black);
    m_Essential.m_Window.display();
    setState();
}


void StateMachine::setState() {
    if(m_Essential.currentState != stateCurrentlySet)
    {
        stateCurrentlySet = m_Essential.currentState;
        switch(stateCurrentlySet)
        {
            case STATES::MENU:
                m_currentState=std::make_unique<MainMenu>(m_Essential);
                break;
            case STATES::EXITING:
                m_currentState=std::make_unique<Exiting>(m_Essential);
                break;
        }
    }
}

void StateMachine::run() {
    while(m_Essential.currentState!=STATES::CLOSING)
    {
        setState();
        m_currentState->run();
    }
    m_Essential.m_Window.close();
}

