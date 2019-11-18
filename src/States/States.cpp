#include "States.h"



Exiting::Exiting(EssentialWindow &Essential) : GameState(Essential) {
    time_left = 3.0;
    m_GoddbyeText.setFont(Essential.m_GlobFont);
    m_GoddbyeText.setCharacterSize(100);
    m_GoddbyeText.setString("GOODBYE");
    sf::Vector2i textsize= sf::Vector2i(m_GoddbyeText.getLocalBounds().height,m_GoddbyeText.getLocalBounds().width);
    m_GoddbyeText.setPosition(0,(GameState::getGamestateEssential()->m_Window.getSize().y/2)-textsize.y/2);
    m_GoddbyeText.setFillColor(sf::Color::Blue);
}

void Exiting::logic() {
    time_left -= GameState::getRenderingTime(0)*100;
    std::string cl = "GOODBYE ";
    cl+= std::to_string(time_left);
    m_GoddbyeText.setString(cl);
    if(time_left<0.0)
    {
        GameState::getGamestateEssential()->nextState = STATES::CLOSING;
    }
}

void Exiting::render() {
    GameState::getGamestateEssential()->m_Window.clear();
    GameState::getGamestateEssential()->m_Window.draw(m_GoddbyeText);
    GameState::getGamestateEssential()->m_Window.display();
}