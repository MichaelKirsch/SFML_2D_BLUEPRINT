#include "MainMenu.h"

MainMenu::MainMenu(EssentialWindow& Essential) : GameState(Essential),m_Gui(Essential){
    b2 = m_Gui.addButton();
    b2->setPositionOfCenter({50,8});
}

void MainMenu::handle_events() {
    m_Gui.update();
    b2->setText("one Frame takes:"+std::to_string(getRenderingTime(0))+" Seconds to load");
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