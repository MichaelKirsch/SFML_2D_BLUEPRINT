

#pragma once

#include <iostream>
#include "../Statemachine/Gamestate.h"
#include "../Statemachine/EssentialWindow.h"



class MainMenu : public GameState
{
public:
    MainMenu(EssentialWindow* window);
    void handle_events(){printf("handle main menu events\n");};
    void logic() {
                    printf("handle main menu logic\n");
                };
    void render(){
        printf("handle main menu rendering shit\n");};
private:
    EssentialWindow* m_window;
};


