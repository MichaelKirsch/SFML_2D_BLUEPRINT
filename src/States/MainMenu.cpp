#include "MainMenu.h"

MainMenu::MainMenu(EssentialWindow& Essential) : GameState(Essential),m_Gui(Essential){
    m1 = m_Gui.addMenu();
    m_Text = m_Gui.addSimpleText();
    m_prog = m_Gui.addProgressBar();
    m_prog2 = m_Gui.addProgressBar(50,150);
    m_prog->setBarColor({255,1,0,200});
    m_prog->setBackground({80,80,80,80});
    m_prog2->setBarColor({1,255,0,200});
    m_prog2->setBackground({80,80,80,80});
    m_prog->setMaxValue(150);
    m_prog->setSize({15,3});
    m_prog->setPosition({10.f,91.f});
    m_prog2->setSize({15,3});
    m_prog2->setPosition({10.f,95.f});
    m_prog2->setOrientation(gui::progressBar::ORIENTATION::HORIZONTAL);
    m_Text->setText("CEASAR 2D");
    m_Text->setSize(13);
    m_Text->setTextColor({52, 207, 235,200});
    m_Text->setPositionOfCenter({50,6});
    m1->createMenu({"Menu"},{" New Game "," Load Game "," Settings "," Exit "});
    auto path_to_pic = std::experimental::filesystem::current_path().parent_path().string();
    path_to_pic+="/data/Pics/90.jpg";
    m_BackTexture.loadFromFile(path_to_pic);
    m_BackgroudPic.setSize({(float)Essential.m_Window.getSize().x,(float)Essential.m_Window.getSize().y});
    m_BackgroudPic.setTexture(&m_BackTexture);
}

void MainMenu::handle_events() {
    m_Gui.update();

    if(m1->getButtonState(" Exit "))
    {
        GameState::getGamestateEssential()->nextState = STATES::EXITING;
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
        getGamestateEssential()->refactor_is_needed = true;
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
    if(m_prog->getValue()<m_prog->getMaxValue())
    {
        m_prog->setValue(m_prog->getValue()+1);
    } else
        m_prog->setValue(0);
    m_prog2->setValue(m_prog->getValue());
}

void MainMenu::render() {
    getGamestateEssential()->m_Window.clear();
    getGamestateEssential()->m_Window.draw(m_BackgroudPic);
    m_Gui.draw();
    getGamestateEssential()->m_Window.display();
}