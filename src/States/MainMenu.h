#pragma once
#include <iostream>
#include "../Statemachine/Gamestate.h"
#include "../Statemachine/EssentialWindow.h"
#include <experimental/filesystem>
#include "../GUI/GuiManager.h"

class MainMenu : public GameState
{
public:
    MainMenu(EssentialWindow& Essential);
    void handle_events() override;
    void logic() override;
    void render() override;
private:
    gui::Manager m_Gui;
    gui::Button* b2;
    gui::Menu* m1;
};


