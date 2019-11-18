#pragma once

#include "SFML/Graphics.hpp"
#include "../Statemachine/StateEnum.h"

struct Style
{
    sf::Color defaultColor ={80,80,80};
    sf::Color textColor ={217, 160, 76};
    //unsigned int roundnessOfCorners = 4;
    unsigned int buttonHeight = 4;
};


class EssentialWindow
{
    public:
        STATES nextState;
        sf::Clock m_Clock;
        sf::RenderWindow m_Window;
        sf::Mouse m_Mouse;
        sf::Font m_GlobFont;
        Style m_GuiStyle;
        float Framerate, Updaterate, Eventrate;
};
