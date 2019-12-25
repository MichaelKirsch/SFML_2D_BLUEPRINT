#pragma once
#include <iostream>
#include "../Statemachine/Gamestate.h"
#include "../Statemachine/EssentialWindow.h"
#include <experimental/filesystem>
#include "../GUI/GuiManager.h"
#include "../Util/Serialization.h"

class MainMenu : public GameState
{
public:
    MainMenu(EssentialWindow& Essential);
    void handle_events() override;
    void logic() override;
    void render() override;
private:
    gui::Manager m_Gui;
    gui::progressBar* m_prog;
    gui::SimpleText* m_Text;
    gui::Menu* m1;
    sf::RectangleShape m_BackgroudPic;
    sf::Texture m_BackTexture;
    SerSettings m_settings;
    SettingsObject m_SetObj;
};


