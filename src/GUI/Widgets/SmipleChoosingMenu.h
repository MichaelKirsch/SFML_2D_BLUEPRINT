

#pragma once

#include <vector>
#include "Button.h"
#include "WidgetBase.h"
#include "SFML/Graphics.hpp"
#include "EssentialWindow.h"
namespace gui
{
    class SmipleChoosingMenu : public Widget
            {
            public:
                SmipleChoosingMenu(EssentialWindow& es,std::string bleft,std::string bright,std::vector<std::string> options);
                void createMenu(std::string button_left="<",std::string button_right=">", std::vector<std::string>buttons={"but1","but2"});
                void appendToMenu(std::vector<std::string> newButtons);
                void setPositionScreenPercent(sf::Vector2i newPos){positionInScreenPercent=newPos;refactor();};
                std::string getCurrentOption(){return m_Options[m_current_option_position];};
                void update();
                void refactor();
                void draw();
            private:
                float timer=0.f;
                sf::Text m_CurrentOptionText;
                int m_current_option_position = 0;
                Button m_ButtonLeft,m_ButtonRight;
                std::vector<std::string> m_Options;
            };
}




