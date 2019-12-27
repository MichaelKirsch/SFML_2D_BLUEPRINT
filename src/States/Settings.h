

#pragma once

#include "Gamestate.h"
#include "GuiManager.h"

class Settings : public GameState {
public:
    Settings(EssentialWindow& Essential);
    void handle_events() override;
    void logic() override;
    void render() override;
private:
    gui::Manager m_Gui;
    gui::SimpleText* m_Text;
    gui::Menu* m1;
};



