#pragma once


#include <memory>
#include "../States/States.h"
#include "../States/MainMenu.h"
#include "../States/ChooseMap.h"
#include "Gamestate.h"
#include "EssentialWindow.h"
#include "StateEnum.h"
#include "experimental/filesystem"

class StateMachine {
public:
    StateMachine(std::string game_name = "Default Name", int framerate = 60, int updaterate = 40, int eventrate=40); //here we set all the essentials
    ~StateMachine() = default;
    void dispatch(STATES dropInto);
    STATES getState() { return m_Essential.nextState;};
    void setState();

private:
    std::string m_GameName = "Default Name";
    STATES stateCurrentlySet;
    EssentialWindow m_Essential;
    std::unique_ptr<GameState> uniquePtrState;
};





