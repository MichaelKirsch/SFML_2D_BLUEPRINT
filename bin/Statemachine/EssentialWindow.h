#pragma once

#include "SFML/Graphics.hpp"
#include "../Statemachine/StateEnum.h"


class EssentialWindow
{
    public:
        STATES nextState;
        sf::Clock m_Clock;
        sf::RenderWindow m_Window;
        sf::Mouse m_Mouse;
};
