#include "MainMenu.h"

MainMenu::MainMenu(EssentialWindow& Essential) : GameState(Essential),m_Gui(Essential){
    b2 = m_Gui.addButton();
    m1 = m_Gui.addMenu();
    m1->createMenu({"Menu"},{"New Game","Load Game","Settings","Exit"});
    b2->setPositionOfCenter({50,5});
    b2->setVisible(false);
}

void MainMenu::handle_events() {
    m_Gui.update();
    b2->setText("one Frame takes:"+std::to_string(getRenderingTime(0))+" Seconds to load");
    if(m1->getButtonState("Exit"))
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