

#pragma once

#include <string>
#include "WidgetBase.h"
#include "../../Statemachine/EssentialWindow.h"

namespace gui
{
    class SimpleText : public Widget {
    public:
        SimpleText(EssentialWindow& es);
        void setText(std::string text);
        void draw();
        void setPositionOfCenter(sf::Vector2u);
        ~SimpleText()= default;

    private:
        void refactor();
        bool isCentered = false;
        std::string m_TextString = "undefined";
        EssentialWindow& m_Essential;
        sf::Text m_Text;
        sf::Vector2u m_Position ={0,0};
    };
}




