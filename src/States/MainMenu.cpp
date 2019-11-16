#include "MainMenu.h"

MainMenu::MainMenu(EssentialWindow& Essential) : GameState(Essential),m_Gui(Essential){
    b2 = m_Gui.addButton();
    b2->setEssentialWindow(&Essential);
    b2->setFillColor(sf::Color::Green);
    b2->setSize({3,3});
    b2->setText("Hello World ");
    b2->setTextColor(sf::Color::White);
    b2->setPositionOfTopLeft({8,8});
}

void MainMenu::handle_events() {
    m_Gui.update();
    b2->setText(std::to_string(cl.getElapsedTime().asSeconds()));
    if(b2->isClicked())
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
    m_Gui.draw();
    getGamestateEssential()->m_Window.display();
}