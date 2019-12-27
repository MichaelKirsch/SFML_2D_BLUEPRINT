

#include "Settings.h"

Settings::Settings(EssentialWindow &Essential) : GameState(Essential),m_Gui(Essential) {
    m1=m_Gui.addMenu();

}

void Settings::handle_events() {
    GameState::handle_events();
}

void Settings::logic() {
    GameState::logic();
}

void Settings::render() {
    GameState::render();
}
