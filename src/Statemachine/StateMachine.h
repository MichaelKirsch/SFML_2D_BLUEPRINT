#pragma once


#include <memory>
#include "../States/States.h"
#include "../States/MainMenu.h"
#include "Gamestate.h"
#include "EssentialWindow.h"
#include "StateEnum.h"
#include "experimental/filesystem"

class StateMachine {
public:
    StateMachine(); //here we set all the essentials
    ~StateMachine() = default;
    void run();
    STATES getState() { return m_Essential.nextState;};
    void setState();

private:
    STATES stateCurrentlySet;
    EssentialWindow m_Essential;
    std::unique_ptr<GameState> uniquePtrState;
};





