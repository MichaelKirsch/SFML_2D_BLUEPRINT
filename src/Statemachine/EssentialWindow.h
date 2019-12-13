#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include <SFML/Audio.hpp>
#include "../Statemachine/StateEnum.h"

struct Style
{
    sf::Color defaultColor ={208, 235, 52};
    sf::Color textColor ={217, 160, 76};
    sf::Color inactiveColor = {20,20,20};
    sf::Color textColorInactive = {200,40,40};
    //unsigned int roundnessOfCorners = 4;
    unsigned int buttonHeight = 4;
    int animationSpeed = 10;
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
        sf::Music m_Music;
        std::string m_PathToParent = "";
        float Framerate, Updaterate, Eventrate;
        sf::Vector2f getPixelValues(sf::Vector2f percentages)
        {
            return {(m_Window.getSize().x/100)*percentages.x,(m_Window.getSize().y/100)*percentages.y};
        }
        sf::Vector2i getMouseRelPos()
        {
            return m_Mouse.getPosition(m_Window);
        }
};
