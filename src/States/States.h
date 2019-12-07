

#pragma once

#include <iostream>
#include "../Statemachine/Gamestate.h"
#include "../Statemachine/EssentialWindow.h"
#include <experimental/filesystem>
#include "../World/simple.h"
class Exiting : public GameState
{
public:
    Exiting(EssentialWindow &Essential);
    void handle_events();
    void logic() override;
    void render() override;

private:
    EssentialWindow& es;
    simple m_test;
    sf::Text m_GoddbyeText;
};
