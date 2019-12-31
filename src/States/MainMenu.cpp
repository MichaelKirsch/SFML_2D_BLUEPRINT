#include "MainMenu.h"

MainMenu::MainMenu(EssentialWindow& Essential) : GameState(Essential){
    m1 = m_Gui.addMenu();
    m_Text = m_Gui.addSimpleText();
    m_Text->setText("Olympus");
    m_Text->setSize(13);
    m_Text->setTextColor({245, 179, 66,200});
    m_Text->setPositionOfCenter({50,6});
    m1->createMenu({"Menu"},{" New Game "," Load Game "," Settings "," Exit "});
    auto path_to_pic = Essential.m_PathToParent+"/data/Pics/90.jpg";
    m_BackTexture.loadFromFile(path_to_pic);
    m_BackgroudPic.setSize({(float)Essential.m_Window.getSize().x,(float)Essential.m_Window.getSize().y});
    m_BackgroudPic.setTexture(&m_BackTexture);
}

void MainMenu::handle_events() {
    m_Gui.update();

    if(m1->getButtonState(" Exit "))
    {
        GameState::getGamestateEssential()->nextState = STATES::CLOSING;
    }
    if(m1->getButtonState(" New Game "))
    {
        GameState::getGamestateEssential()->nextState = STATES::CHOOSE_MAP;
    }
    if(m1->getButtonState(" Load Game "))
    {

    }

    if(m1->getButtonState(" Settings "))
    {
        GameState::getGamestateEssential()->nextState = STATES::SETIINGS;
    }

    sf::Event m_Event;
    while (getGamestateEssential()->m_Window.pollEvent(m_Event))
    {
        if (m_Event.type == sf::Event::Closed )
        {
            GameState::getGamestateEssential()->nextState = STATES::CLOSING;
        }
    }
}

void MainMenu::logic() {

}

void MainMenu::render() {
    getGamestateEssential()->m_Window.clear();
    getGamestateEssential()->m_Window.draw(m_BackgroudPic);
    m_Gui.draw();
    getGamestateEssential()->m_Window.display();
}