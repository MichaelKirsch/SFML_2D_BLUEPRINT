//
// Created by micha on 19.12.2019.
//

#include "Serialization.h"

const void SerSettings::serialize(SettingsObject *obj) {
    std::ofstream out(m_Essential.m_PathToParent+"/data/Settings/Settings.mkf");
    out.write(reinterpret_cast<char*>(&obj), sizeof(obj));
}

const void SerSettings::deserialize(SettingsObject *obj) {
    std::ifstream in(m_Essential.m_PathToParent+"/data/Settings/Settings.mkf");
    in.read(reinterpret_cast<char*>(&obj), sizeof(obj));
}
