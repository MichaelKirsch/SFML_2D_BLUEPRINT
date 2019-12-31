

#pragma once

#include "Gamestate.h"
#include "../GUI/GuiManager.h"

class Game : public GameState {
public:
    Game(EssentialWindow& es);
    ~Game()= default;
    void handle_events() override;
    void logic() override;
    void render() override;
private:
    gui::SimpleText* m_simple;
protected:
};



