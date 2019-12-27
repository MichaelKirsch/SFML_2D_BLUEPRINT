

#pragma once

#include <string>
#include "WidgetBase.h"
#include "../../Statemachine/EssentialWindow.h"

namespace gui
{
    class SimpleText : public Widget {
    public:
        SimpleText(EssentialWindow& es);
        void setSize(int size);
        void setText(std::string text);
        void setTextColor(sf::Color colorToSet);
        void draw();
        void setPositionOfCenter(sf::Vector2u);
        ~SimpleText()= default;

    private:
        void refactor();
        bool isCentered = false;
        std::string m_TextString = "undefined";
        sf::Text m_Text;
        sf::Vector2u m_Position ={0,0};
    };
}




