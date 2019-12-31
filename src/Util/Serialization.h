#pragma once
#include <string>
#include <SFML/Audio.hpp>
#include "EssentialWindow.h"
#include <fstream>
#include "json/json.hpp"
#include "experimental/filesystem"
#include <iostream>

namespace serial
{
    struct SettingsObject
    {
        float version; //this will be needed to stop old savegames from beeing used
        bool fullscreen;
        bool getNativeResolution;
        bool useVsync;
    };

    class SerializableObject
    {
    public:

        void out()
        {
        }

        void in()
        {
            std::string path= std::experimental::filesystem::current_path().parent_path().string();
            path+="/data/Profiles/default.profile";
            std::ifstream o(path);
            nlohmann::json buf;
            o>>buf;
            std::string tz = buf.at("name");
            bool fullscreen = buf.at("fullscreen");
            std::cout<< tz<< (fullscreen?" yes":"no")<<std::endl;
        }

        nlohmann::json j2 = {
                {"pi", 3.141},
                {"happy", true},
                {"name", "Niels"},
                {"nothing", nullptr},
                {"answer", {
                               {"everything", 42}
                       }},
                {"list", {1, 0, 2}},
                {"object", {
                               {"currency", "USD"},
                             {"value", 42.99}
                       }}
        };
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
}





