

#pragma once

#include "EssentialWindow.h"
#include "WidgetBase.h"

namespace gui
{
    class ToggleButton : public Widget  {
    public:
        ToggleButton(EssentialWindow& es);
        void setName(std::string name){m_name=name;refactor();};
        void toggle();
        void setStatus(bool stat){m_status = stat;refactor();};
        void setPosition(sf::Vector2f pos){m_position=pos;refactor();};
        bool getStatus(){ return m_status;};
        void setSize(int size){m_size = size;refactor();};
        void draw();
        void update();
    private:
        void refactor();
        float time_since_last_toggle=0.f;
        sf::RectangleShape buffer;
        sf::Color button_active={0,0,255};
        sf::Color button_inactive = {50,50,50};
        std::string m_name="default";
        bool m_status = false;
        int m_size = 10;
        sf::RectangleShape m_body;
        sf::CircleShape m_knob;
        sf::Text m_buttonText;
        sf::Vector2f m_position={0.f,0.f};
    };
}




