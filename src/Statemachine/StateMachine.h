#pragma once


#include <memory>
#include "../States/MainMenu.h"
#include "../States/ChooseMap.h"
#include "../States/Settings.h"
#include "Gamestate.h"
#include "EssentialWindow.h"
#include "StateEnum.h"
#include "experimental/filesystem"
#include "json/json.hpp"

class StateMachine {
public:
    StateMachine(std::string game_name = "Default Name", int framerate = 60, int updaterate = 40, int eventrate=100 ,bool fullscreen = false); //here we set all the essentials
    StateMachine(std::string game_name = "Default Name",std::string profile_name  = "default.profile"); //load from profile
    ~StateMachine() = default;
    void dispatch(STATES dropInto);
    STATES getState() { return m_Essential.nextState;};
    void setState();
private:
    void refactor();
    nlohmann::json buffer;
    std::string m_GameName = "Default Name";
    std::string m_ProfileName = "default.profile";
    STATES stateCurrentlySet;
    EssentialWindow m_Essential;
    std::unique_ptr<GameState> uniquePtrState;
};





