

#pragma once

#include "../Statemachine/Gamestate.h"
#include "../GUI/GuiManager.h"


class ChooseMap : public GameState {
public:
    ChooseMap(EssentialWindow& es);
    void handle_events() override;
    void logic() override;
    void render() override;
    ~ChooseMap()= default;

private:
    EssentialWindow& m_Essential;
    gui::Manager m_GuiManager;
    gui::SimpleText* seedText;
    gui::Button* nextMap;
    gui::Button* useThisMap;
    gui::Button* backButton;
    sf::RectangleShape map;
};



