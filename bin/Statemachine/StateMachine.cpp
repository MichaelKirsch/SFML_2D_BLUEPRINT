#include "StateMachine.h"


StateMachine::StateMachine() {
    m_Essential.m_Window.create(sf::VideoMode(1000,1000),"Hello");
    m_Essential.m_Window.clear(sf::Color::Black);
    m_Essential.m_Window.display();
    m_Essential.nextState = STATES::MENU; //we want to start with the menu
    setState();
}


void StateMachine::setState() {
    if(m_Essential.nextState != stateCurrentlySet)
    {
        switch(m_Essential.nextState)
        {
            case STATES::MENU:
                uniquePtrState=std::make_unique<MainMenu>(m_Essential);
                break;
            case STATES::EXITING:
                uniquePtrState=std::make_unique<Exiting>(m_Essential);
                break;
        }
        stateCurrentlySet = m_Essential.nextState;
    }
}

void StateMachine::run() {
    while(m_Essential.nextState != STATES::CLOSING)
    {
        setState();
        uniquePtrState->run();
    }
    m_Essential.m_Window.close();
}
