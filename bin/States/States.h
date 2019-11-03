

#pragma once

#include <iostream>
#include "../Statemachine/Gamestate.h"

class MainMenu : public GameState
{
public:
    MainMenu(){};
    ~MainMenu(){};
    void handle_events(){printf("handle main menu events");};
    void logic() {printf("handle main menu logic");};
    void render(){printf("handle main menu rendering shit");};
};


