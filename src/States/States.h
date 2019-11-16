

#pragma once

#include <iostream>
#include "../Statemachine/Gamestate.h"
#include "../Statemachine/EssentialWindow.h"
#include <experimental/filesystem>
#include "../GUI/GUI.h"




class Exiting : public GameState
{
public:
    Exiting(EssentialWindow& Essential);
    void handle_events(){};
    void logic() override;
    void render() override;

private:
    float time_left;
    sf::Text m_GoddbyeText;
    sf::Font m_Font;
    sf::Clock m_closingClock;
};
