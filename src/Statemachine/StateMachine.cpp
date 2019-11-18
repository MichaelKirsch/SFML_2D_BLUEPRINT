#include "StateMachine.h"


StateMachine::StateMachine() {
    m_Essential.m_Window.create(sf::VideoMode(1000,1000),"Hello");
    m_Essential.m_Window.clear(sf::Color::Black);
    m_Essential.m_Window.display();
    m_Essential.Framerate = 60;
    m_Essential.Updaterate = 40;
    m_Essential.Eventrate = 50;
    m_Essential.m_GuiStyle.textColor=sf::Color::Green;
    stateCurrentlySet = STATES :: NONE;
    std::string path= std::experimental::filesystem::current_path().parent_path().string();
    path+="/data/Font/Ubuntu-R.ttf";
    if(!m_Essential.m_GlobFont.loadFromFile(path))
    {
        std::cout<<"FONT DIDNT LOAD"<<std::endl;
    }
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
