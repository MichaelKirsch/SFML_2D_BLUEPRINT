#include "States.h"



Exiting::Exiting(EssentialWindow &Essential) : GameState(Essential) {
    time_left = 3.0;
    b1.setEssentialWindow(&Essential);
    b1.setPositionOfTopLeft({80,0});
    b1.setFillColor(sf::Color::Red);
    b1.setSize({5,5});
    b1.setText("Back ");
    m_GoddbyeText.setFont(Essential.m_GlobFont);
    m_GoddbyeText.setCharacterSize(100);
    m_GoddbyeText.setString("GOODBYE");
    sf::Vector2i textsize= sf::Vector2i(m_GoddbyeText.getLocalBounds().height,m_GoddbyeText.getLocalBounds().width);
    m_GoddbyeText.setPosition(0,(GameState::getGamestateEssential()->m_Window.getSize().y/2)-textsize.y/2);
    m_GoddbyeText.setFillColor(sf::Color::Blue);
}

void Exiting::logic() {
    b1.update();
    if(b1.isClicked())
    {
        GameState::getGamestateEssential()->nextState = STATES::MENU;
    }
    time_left -= m_closingClock.restart().asSeconds();
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
    b1.draw();
    GameState::getGamestateEssential()->m_Window.draw(m_GoddbyeText);
    GameState::getGamestateEssential()->m_Window.display();
}