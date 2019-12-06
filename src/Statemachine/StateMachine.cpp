#include "StateMachine.h"


StateMachine::StateMachine(std::string game_name) : m_GameName(game_name) {
    m_Essential.m_Window.create(sf::VideoMode::getDesktopMode(),m_GameName);

    m_Essential.m_Window.clear(sf::Color::Black);
    m_Essential.m_Window.display();
    m_Essential.Framerate = 60;
    m_Essential.Updaterate = 30;
    m_Essential.Eventrate = 50;
    m_Essential.m_GuiStyle.textColor={201, 165, 111};
    m_Essential.m_GuiStyle.defaultColor={45, 45, 42};
    stateCurrentlySet = STATES :: NONE;
    std::string path= std::experimental::filesystem::current_path().parent_path().string();
    m_Essential.m_PathToParent = path;
    path+="/data/Font/Ubuntu-R.ttf";
    if(!m_Essential.m_GlobFont.loadFromFile(path))
    {
        std::cout<<"FONT DIDNT LOAD"<<std::endl;
    }
    m_Essential.nextState = STATES::MENU; //we want to start with the menu
    sf::Image icon;
    icon.loadFromFile(m_Essential.m_PathToParent+"/data/Pics/icon.png"); // File/Image/Pixel
    m_Essential.m_Window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

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
            case STATES::CHOOSE_MAP:
                uniquePtrState=std::make_unique<ChooseMap>(m_Essential);
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
