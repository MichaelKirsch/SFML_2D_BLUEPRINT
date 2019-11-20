

#include "ChooseMap.h"

ChooseMap::ChooseMap(EssentialWindow &es) : GameState(es),m_Essential(es),m_GuiManager(es) {
    nextMap = m_GuiManager.addButtonCentered("Next Map",{80,50-2*m_Essential.m_GuiStyle.buttonHeight});
    useThisMap = m_GuiManager.addButtonCentered("Use this Map",{80,50});
    backButton = m_GuiManager.addButtonCentered("Back",{80,50+2*m_Essential.m_GuiStyle.buttonHeight});
    seedText = m_GuiManager.addSimpleTextCentered("Seed:",{80,50+4*m_Essential.m_GuiStyle.buttonHeight});
}

void ChooseMap::handle_events() {
    m_GuiManager.update();
    if(backButton->isClicked())
    {
        m_Essential.nextState = STATES :: MENU;
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

void ChooseMap::render() {
    m_Essential.m_Window.clear();
    m_GuiManager.draw();
    m_Essential.m_Window.display();
}

void ChooseMap::logic() {

}
