#pragma once


#include <memory>
#include "../States/States.h"
#include "../GUI.h"
#include "Gamestate.h"
#include "EssentialWindow.h"
#include "StateEnum.h"

class StateMachine {
public:
    StateMachine();
    ~StateMachine() = default;
    void run();
    STATES getState() { return m_Essential.currentState;};
    void setState();

private:
    STATES stateCurrentlySet;
    EssentialWindow m_Essential;
    std::unique_ptr<GameState> m_currentState;
};





