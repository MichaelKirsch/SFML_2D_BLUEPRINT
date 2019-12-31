

#pragma once

#include "json/json.hpp"
#include "Gamestate.h"
#include "GuiManager.h"
#include <fstream>

class Settings : public GameState {
public:
    Settings(EssentialWindow& Essential);
    void handle_events() override;
    void logic() override;
    void render() override;
private:
    gui::SmipleChoosingMenu* m_Resolutions;
    gui::ToggleButton* m_fullscreen;
    gui::ToggleButton* m_vsync;
    gui::Button* back;
    nlohmann::json settings;
};



