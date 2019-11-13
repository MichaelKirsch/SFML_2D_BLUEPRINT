#include "States.h"

MainMenu::MainMenu(EssentialWindow& Essential) : GameState(Essential){
    m_but.setEssentialWindow(&Essential);
    b2.setEssentialWindow(&Essential);
    b2.setFillColor(sf::Color::Green);
    b2.setSize({3,3});
    b2.setPositionOfTopLeft({8,8});
    m_but.setFillColor(sf::Color::Blue);
    m_but.setSize({5,5});
    m_but.setPositionOfTopLeft({50,50});
}

void MainMenu::handle_events() {
    m_but.update();
    b2.update();
    if(b2.isClicked())
    {
        m_but.setFillColor(sf::Color::Yellow);
    }
    if(m_but.isClicked())
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
    getGamestateEssential()->m_Window.clear();
    sf::RectangleShape p;
    p.setSize(sf::Vector2f(100,100));
    p.setPosition(100,100);
    getGamestateEssential()->m_Window.draw(p);
    m_but.draw();
    b2.draw();
    getGamestateEssential()->m_Window.display();
}

Exiting::Exiting(EssentialWindow &Essential) : GameState(Essential) {
    time_left = 3.0;
    b1.setEssentialWindow(&Essential);
    b1.setPositionOfTopLeft({10,10});
    b1.setFillColor(sf::Color::Red);
    b1.setSize({5,5});
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