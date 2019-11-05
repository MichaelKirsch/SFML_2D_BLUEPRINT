#pragma once

#include "SFML/Graphics.hpp"
#include "../Statemachine/StateEnum.h"


class EssentialWindow
{
    public:
        STATES currentState;
        sf::Clock m_Clock;
        sf::RenderWindow m_Window;
        sf::Mouse m_Mouse;
};
