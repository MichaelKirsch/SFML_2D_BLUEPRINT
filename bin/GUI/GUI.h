

#pragma once

#include "../Statemachine/EssentialWindow.h"

namespace gui
{
    class Button
    {
    //the button position is always the top left. but you can receive the center
    public:
        Button()= default;
        Button(EssentialWindow* es, sf::Vector2u pos = {0,0}, std::string text = "not configured yet", sf::Vector2u size ={5,5});
        //Button(EssentialWindow&es, Style);
        ~Button();
        void draw();
        void setEssentialWindow(EssentialWindow* );
        void setSize(sf::Vector2u);
        void setFillColor(sf::Color newColor);
        void update();
        bool isClicked();
        void setPositionOfTopLeft(sf::Vector2u pos);
        void setPositionOfCenter(sf::Vector2u pos);
    private:
        void refactor();//this function will be called when there is any change in size color or anything like that
        bool mouseOver;
        sf::RectangleShape m_Rect;
        EssentialWindow* m_Essential;
        std::string m_Text;
        sf::Vector2u m_Size,m_Pos = {0,0};
        sf::Color m_FillColor,m_MouseOver,m_CurrentRectCol;
    };

}


