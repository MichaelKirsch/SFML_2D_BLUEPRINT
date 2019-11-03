#pragma once

#include "SFML/Graphics.hpp"
#include "../Window.h"
#include "../GUI.h"

struct EssentialWindow
{
    sf::Clock m_Clock;
    Window m_window;
    GUI m_GUI;
    EssentialWindow() : m_GUI(&m_window){};
};
