

#include "States.h"

MainMenu::MainMenu(EssentialWindow& Essential) : GameState(Essential){
    m_But.setWindow(&Essential);
}

void MainMenu::handle_events() {

    if(m_But.mouseover()&&getGamestateEssential()->m_Mouse.isButtonPressed(sf::Mouse::Button::Left))
    {
        GameState::getGamestateEssential()->nextState = STATES::EXITING;
    }
    sf::Event m_Event;
    while (getGamestateEssential()->m_Window.pollEvent(m_Event))
    {
        if (m_Event.type == sf::Event::Closed )
        {
            GameState::getGamestateEssential()->nextState = STATES::EXITING;
        }
    }
}

void MainMenu::logic() {
}

void MainMenu::render() {
    sf::RectangleShape p;
    p.setSize(sf::Vector2f(100,100));
    p.setPosition(100,100);
    m_But.draw();
    getGamestateEssential()->m_Window.draw(p);
    getGamestateEssential()->m_Window.display();
}

Exiting::Exiting(EssentialWindow &Essential) : GameState(Essential) {
    time_left =3.0;
    std::string po = std::experimental::filesystem::current_path().parent_path().string();
    po+="/Data/Font/arial.ttf";
    m_Font.loadFromFile(po);
    m_GoddbyeText.setFont(m_Font);
    m_GoddbyeText.setCharacterSize(100);
    m_GoddbyeText.setString("GOODBYE");
    sf::Vector2i textsize= sf::Vector2i(m_GoddbyeText.getLocalBounds().height,m_GoddbyeText.getLocalBounds().width);
    m_GoddbyeText.setPosition(0,(GameState::getGamestateEssential()->m_Window.getSize().y/2)-textsize.y/2);
    m_GoddbyeText.setFillColor(sf::Color::Blue);
}

void Exiting::logic() {
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
    GameState::getGamestateEssential()->m_Window.draw(m_GoddbyeText);
    GameState::getGamestateEssential()->m_Window.display();
}
