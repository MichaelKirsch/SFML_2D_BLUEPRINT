#pragma once
#include <string>
#include <SFML/Audio.hpp>
#include "EssentialWindow.h"
#include <fstream>

struct SettingsObject
{
    float version; //this will be needed to stop old savegames from beeing used
    bool fullscreen;
    bool getNativeResolution;
    bool useVsync;
};

class SerSettings
{
public:
    SerSettings(EssentialWindow& es):m_Essential(es){};
    ~SerSettings()= default;
    const void serialize(SettingsObject* obj);
    const void deserialize(SettingsObject *obj);
private:
    EssentialWindow& m_Essential;
};


