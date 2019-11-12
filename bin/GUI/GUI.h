#pragma once

#include "../Statemachine/EssentialWindow.h"
#include <experimental/filesystem>
#include <vector>
#include <string>
#include <iostream>

namespace GameGui
{
    class Button
    {
    public:
        Button();
        void setWindow(EssentialWindow* es);
        void draw();
        bool mouseover();
    private:
        std::string m_string;
        EssentialWindow* es;
        sf::Color rectCol;
        sf::Color defa{100,100,100};
        sf::Color moc{245, 167, 66};
        sf::Color textcol{255,255,255};
        sf::Text m_Text;
        sf::RectangleShape m_Rect;
        sf::Vector2u pos;
        sf::Font m_Font;
    };
}


