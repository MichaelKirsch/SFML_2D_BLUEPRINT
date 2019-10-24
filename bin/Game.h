#pragma once

#include "StateMashine.h"
#include "World.h"
#include "Window.h"
#include "GUI.h"
#include "NPCManager.h"
#include "ChunkManager.h"

class MainGameManager {
public:
    MainGameManager();

    ~MainGameManager() = default;

    void run();
private:
    void handleEvents();
    void update();
    void draw();

    sf::Clock m_Clock;
    float m_ElapsedTime;
    StateMashine m_Statemashine;
    World m_World;
    GUI m_Gui;
    Window m_Window;
    NPCmanager m_NPCmanager;
    Chunkmanager m_Chunkmanager;
};



