

#include "Settings.h"

Settings::Settings(EssentialWindow &Essential) : GameState(Essential),m_Gui(Essential) {
    back = m_Gui.addButton("Save&Back",{40,32});
    m_Text = m_Gui.addSimpleText("Settings");
    m_Resolutions = m_Gui.addSimpleChoosingMenu("<",">",{"1920x1080","1000x1000","1600x900","1200,600"});
    m_Resolutions->setPositionScreenPercent({40,12});
    std::ifstream o(Essential.m_PathToParent+"/data/Profiles/default.profile");
    o>>settings;
    m_fullscreen = m_Gui.addToggleButton("Fullscreen:",{40,19},settings.at("fullscreen"));
    m_vsync = m_Gui.addToggleButton("Vsync:",{40,26},settings.at("vsync"));
}

void Settings::handle_events() {
    m_Gui.update();
    if(back->isClicked())
    {
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
    getGamestateEssential()->m_Window.clear();
    m_Gui.draw();
    getGamestateEssential()->m_Window.display();
}
