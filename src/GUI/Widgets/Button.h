#pragma once

#include "SFML/Graphics.hpp"
#include <vector>
#include "../../Statemachine/EssentialWindow.h"
#include "WidgetBase.h"
namespace gui
{
    class Button : public Widget
    {
        //the button position is always the top left. but you can receive the center
    public:
        Button(EssentialWindow& es, sf::Vector2u pos = {0,0}, std::string text = "not configured yet", unsigned int width = 1);
        ~Button();
        void draw();
        sf::FloatRect getGlobalBounds(){ return m_Rect.getGlobalBounds();};
        void setVisible(bool visibility);
        void setSize(int newSize);
        void setTextColor(sf::Color newColor);
        void setFillColor(sf::Color newColor);
        void update();
        void setText(std::string);
        std::string getText();
        bool isClicked();
        void setPositionOfTopLeft(sf::Vector2u pos);
        void setPositionOfCenter(sf::Vector2u pos);
    private:
        sf::Text m_Text;
        void refactor();//this function will be called when there is any change in size color or anything like that
        bool mouseOver;
        bool isCentered = false;
        sf::RectangleShape m_Rect;
        sf::Vector2u m_Size,m_Pos = {0,0};
        sf::Color m_FillColor,m_MouseOver,m_TextCol;
    };
}




