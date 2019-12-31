

#include "Settings.h"

Settings::Settings(EssentialWindow &Essential) : GameState(Essential) {
    back = m_Gui.addButton("Save&Back",{40,32});
    m_Resolutions = m_Gui.addSimpleChoosingMenu("<",">",{"1920x1080","1600x900","1440x900","1280x800"});
    m_Resolutions->setPositionScreenPercent({40,12});
    std::ifstream o(Essential.m_PathToParent+"/data/Profiles/default.profile");
    o>>settings;
    m_fullscreen = m_Gui.addToggleButton("Fullscreen:",{40,19},settings.at("fullscreen"));
    m_vsync = m_Gui.addToggleButton("Vsync:",{40,26},settings.at("vsync"));
}

void Settings::handle_events() {
    GameState::handle_events();
    if(back->isClicked())
    {
        std::string res = m_Resolutions->getCurrentOption();
        int width,height;
        if(res=="1920x1080")
        {
            width=1920;
            height=1080;
        }
        if(res=="1600x900")
        {
            width=1600;
            height=900;
        }
        if(res=="1440x900")
        {
            width=1440;
            height=900;
        }
        if(res=="1280x800")
        {
            width=1280;
            height=800;
        }
        settings.at("width") = width;
        settings.at("height") = height;
        std::ofstream o(getGamestateEssential()->m_PathToParent+"/data/Profiles/default.profile");
        o<<settings;
        getGamestateEssential()->refactor_is_needed=true;
        getGamestateEssential()->nextState = STATES :: MENU;
    }
}

void Settings::logic() {
    settings.at("fullscreen") = m_fullscreen->getStatus();
    settings.at("vsync") = m_vsync->getStatus();
}

void Settings::render() {
    GameState::render();
    getGamestateEssential()->m_Window.display();
}
