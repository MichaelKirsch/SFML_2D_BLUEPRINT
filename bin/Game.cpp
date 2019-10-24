
#include "Game.h"

MainGameManager::MainGameManager() {
    m_Statemashine.init(&m_CentralClock);
    m_Window.init(&m_CentralClock, &m_Statemashine);
    m_World.init(&m_CentralClock, &m_Statemashine, &m_Window);
    m_Gui.init(&m_CentralClock, &m_Statemashine, &m_Window, &m_World);
    m_NPCmanager.init(&m_CentralClock, &m_Statemashine, &m_Window, &m_World);
    m_Soundmanager.init(&m_CentralClock, &m_Statemashine, &m_Window, &m_World, &m_NPCmanager);
    m_Chunkmanager.init(&m_CentralClock, &m_Statemashine, &m_Window, &m_World);
}

void MainGameManager::run() {

}

