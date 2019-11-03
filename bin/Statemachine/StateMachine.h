#pragma once

#include <memory>
#include "../States/States.h"
#include "../Window.h"
#include "../GUI.h"
#include "Gamestate.h"

enum class STATES {
    MENU, RUNNING, CHOOSE_MAP, CHAR_BUILDER,EXITING
};

struct EssentialWindow
{
    Window m_window;
    GUI m_GUI;
    EssentialWindow() : m_GUI(&m_window){};
};



class StateMachine {
public:
    StateMachine();
    ~StateMachine() = default;
    void run();
    void tick();
    STATES getState() { return m_GlobalGameState;};
    void setState(STATES stateToSet);

private:
    EssentialWindow m_Essential;
    std::unique_ptr<GameState> m_currentState;
    STATES m_GlobalGameState;
};





