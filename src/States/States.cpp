#include "States.h"



Exiting::Exiting(EssentialWindow &Essential) : GameState(Essential), es(Essential){
    m_test.setPointer(&Essential);
}

void Exiting::logic() {
    m_test.update();
}

void Exiting::render() {
    GameState::getGamestateEssential()->m_Window.clear();
    GameState::getGamestateEssential()->m_Window.draw(m_test.map,&m_test.m_text);
    //GameState::getGamestateEssential()->m_Window.draw(m_test.tile_overlay);
    GameState::getGamestateEssential()->m_Window.draw(m_test.mouse_rect);
    GameState::getGamestateEssential()->m_Window.display();
}

void Exiting::handle_events() {
    sf::Event m_Event;
    while (getGamestateEssential()->m_Window.pollEvent(m_Event))
    {
        //TODO set some state vars when polling
    }
}
