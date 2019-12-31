

#include "Game.h"

Game::Game(EssentialWindow &es) : GameState(es) {
    m_simple = m_Gui.addSimpleText();
}

void Game::handle_events() {
    GameState::handle_events();
}

void Game::logic() {
    GameState::logic();
}

void Game::render() {
    GameState::render();
}
