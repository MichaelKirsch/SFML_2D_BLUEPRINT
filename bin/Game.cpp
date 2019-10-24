
#include "Game.h"

MainGameManager::MainGameManager() {
    m_Statemashine.init(&m_ElapsedTime);
    m_Window.init(&m_ElapsedTime, &m_Statemashine);
    m_World.init(&m_ElapsedTime, &m_Statemashine, &m_Window);
    m_Gui.init(&m_ElapsedTime, &m_Statemashine, &m_Window, &m_World);
    m_NPCmanager.init(&m_ElapsedTime, &m_Statemashine, &m_Window, &m_World);
    m_Chunkmanager.init(&m_ElapsedTime, &m_Statemashine, &m_Window, &m_World);
}

void MainGameManager::run() {
    while (m_Window.getWindow()->isOpen()||m_Statemashine.getState()!=StateMashine::STATES::EXITING)
    {
        m_ElapsedTime = m_Clock.restart().asMilliseconds(); //you can go down to microseconds if needed
        handleEvents();
        update();
        draw();
    }
    //some code that saves od prompts you to do so could go here
}

void MainGameManager::handleEvents() {

}

void MainGameManager::update() {

}

void MainGameManager::draw() {

}

