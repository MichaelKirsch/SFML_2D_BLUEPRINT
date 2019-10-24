#pragma once

#include "StateMashine.h"
#include "World.h"
#include "Window.h"
#include "GUI.h"
#include "NPCManager.h"
#include "Soundmanager.h"
#include "ChunkManager.h"

class MainGameManager {
public:
    MainGameManager();

    ~MainGameManager() = default;

    void run();
private:
    float m_CentralClock;
    StateMashine m_Statemashine;
    World m_World;
    GUI m_Gui;
    Window m_Window;
    NPCmanager m_NPCmanager;
    Soundmanager m_Soundmanager;
    Chunkmanager m_Chunkmanager;
};



