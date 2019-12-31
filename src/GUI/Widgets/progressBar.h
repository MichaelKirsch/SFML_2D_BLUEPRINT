#pragma once

#include "WidgetBase.h"
#include "SFML/Graphics.hpp"

namespace gui
{
    class progressBar : public Widget{
    public:
        progressBar(EssentialWindow& m_es);
        void setValue(int value){m_value =value;refactor();};
        void setMaxValue(int max){m_maxValue=max;refactor();};
        void update();
        void draw();
        void setOrientation(ORIENTATION orie){m_orientation=orie;};
        void setPosition(sf::Vector2f);
        void setBackground(sf::Color col){m_backgroundColor=col;refactor();};
        void setBarColor(sf::Color col){m_progressColor=col;refactor();};
        int getValue(){ return m_value;};
        int getMaxValue(){ return m_maxValue;};
        void setValueTextVisible(bool status){m_textIsShown=status;};
        void setSize(sf::Vector2i size){m_size=size;refactor();};
        sf::Vector2u getSize();
        ~progressBar() = default;
    private:
        ORIENTATION m_orientation = ORIENTATION::HORIZONTAL;
        void refactor();
        const int progressRange = 100;
        int m_value = 50;
        int m_maxValue = 100;
        bool m_textIsShown = false;
        sf::Vector2f m_position = {0,0};
        sf::Vector2i m_size = {5,5};
        sf::RectangleShape m_backgroundShape;
        sf::RectangleShape m_progressShape;
        sf::RectangleShape restShape;
        sf::Color m_progressColor = sf::Color::Green;
        sf::Color m_backgroundColor = {80,80,80};
        sf::Text valueText;
    };

}



