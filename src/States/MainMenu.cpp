#include "MainMenu.h"

MainMenu::MainMenu(EssentialWindow& Essential) : GameState(Essential),m_Gui(Essential),m_settings(Essential){
    m1 = m_Gui.addMenu();
    m_Text = m_Gui.addSimpleText();
    m_prog = m_Gui.addProgressBar(50,100);
    m_prog->setBarColor(sf::Color::Red);
    m_prog->setMaxValue(150);
    m_prog->setSize({15,6});
    m_prog->setPosition({30.f,10.f});
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
        m_SetObj.version = this->getRuntimeOfState();
        m_settings.serialize(&m_SetObj);
    }

    if(m1->getButtonState(" Settings "))
    {
        printf("%f\n",m_SetObj.version);
        m_settings.deserialize(&m_SetObj);
        printf("%f\n",m_SetObj.version);
        this->m_Text->setText(std::to_string(m_SetObj.version));
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
}

void MainMenu::render() {
    getGamestateEssential()->m_Window.clear();
    getGamestateEssential()->m_Window.draw(m_BackgroudPic);
    m_Gui.draw();
    getGamestateEssential()->m_Window.display();
}