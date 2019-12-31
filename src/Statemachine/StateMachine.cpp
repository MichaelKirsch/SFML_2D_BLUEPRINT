#include "StateMachine.h"


    StateMachine::StateMachine(std::string game_name, int framerate, int updaterate, int eventrate, bool fullscreen) : m_GameName(game_name) {
        if(fullscreen)
            m_Essential.m_Window.create(sf::VideoMode::getDesktopMode(),m_GameName,sf::Style::None);
        else
            m_Essential.m_Window.create(sf::VideoMode{800,600},m_GameName,sf::Style::None);

        m_Essential.m_Window.clear(sf::Color::Black);
        m_Essential.m_Window.display();
        m_Essential.Framerate = framerate;
        m_Essential.Updaterate = updaterate;
        m_Essential.Eventrate = eventrate;
        stateCurrentlySet = STATES :: NONE;
        std::string path= std::experimental::filesystem::current_path().parent_path().string();
        m_Essential.m_PathToParent = path;
        path+="/data/Font/Ubuntu-R.ttf";
        if(!m_Essential.m_GlobFont.loadFromFile(path))
        {
            std::cout<<"FONT DIDNT LOAD"<<std::endl;
        }
        sf::Image icon;
        icon.loadFromFile(m_Essential.m_PathToParent+"/data/Pics/build.png"); // File/Image/Pixel
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
            case STATES::SETIINGS:
                uniquePtrState=std::make_unique<Settings>(m_Essential);
                break;
            case STATES::CHOOSE_MAP:
                uniquePtrState=std::make_unique<ChooseMap>(m_Essential);
                break;
        }
        stateCurrentlySet = m_Essential.nextState;
    }
}

void StateMachine::dispatch(STATES dropInto) {
    m_Essential.nextState = dropInto;
    while(m_Essential.nextState != STATES::CLOSING )
    {
        if(m_Essential.refactor_is_needed)
            refactor();
        setState();
        uniquePtrState->run();
    }
    m_Essential.m_Window.close();
}

StateMachine::StateMachine(std::string game_name,std::string profile): m_GameName(game_name) {
    std::string path= std::experimental::filesystem::current_path().parent_path().string();
    m_Essential.m_PathToParent = path;
    path+="/data/Font/Ubuntu-R.ttf";
    if(!m_Essential.m_GlobFont.loadFromFile(path))
    {
        std::cout<<"FONT DIDNT LOAD"<<std::endl;
    }
    m_ProfileName = profile;
    std::string path_profile = m_Essential.m_PathToParent+"/data/Profiles/"+profile;
    std::ifstream o(path_profile);
    o>>buffer;
    if(buffer.at("fullscreen"))
        m_Essential.m_Window.create(sf::VideoMode::getDesktopMode(),m_GameName,sf::Style::None);
    else
        m_Essential.m_Window.create(sf::VideoMode{buffer.at("width"),buffer.at("height")},m_GameName,sf::Style::None);
    m_Essential.m_Window.clear(sf::Color::Black);
    m_Essential.m_Window.display();
    m_Essential.m_Window.setVerticalSyncEnabled(buffer.at("vsync"));
    m_Essential.Framerate = buffer.at("framerate");
    m_Essential.Updaterate = buffer.at("updaterate");;
    m_Essential.Eventrate = buffer.at("eventrate");;
    stateCurrentlySet = STATES :: NONE;
    sf::Image icon;
    icon.loadFromFile(m_Essential.m_PathToParent+"/data/Pics/build.png"); // File/Image/Pixel
    m_Essential.m_Window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

void StateMachine::refactor() {
    std::string path_profile = m_Essential.m_PathToParent+"/data/Profiles/"+m_ProfileName;
    std::ifstream o(path_profile);
    buffer.clear();
    o>>buffer;

    if(buffer.at("fullscreen"))
        m_Essential.m_Window.create(sf::VideoMode::getDesktopMode(),m_GameName,sf::Style::None);
    else
        m_Essential.m_Window.create(sf::VideoMode{buffer.at("width"),buffer.at("height")},m_GameName,sf::Style::None);
    m_Essential.m_Window.clear(sf::Color::Black);
    m_Essential.m_Window.display();
    m_Essential.m_Window.setVerticalSyncEnabled(buffer.at("vsync"));
    m_Essential.Framerate = buffer.at("framerate");
    m_Essential.Updaterate = buffer.at("updaterate");
    m_Essential.Eventrate = buffer.at("eventrate");
    m_Essential.refactor_is_needed = false;
}

