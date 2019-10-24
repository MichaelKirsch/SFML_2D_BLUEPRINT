#pragma once
#include "SFML/Graphics.hpp"
#include "StateMashine.h"

class Window {
public:
    Window();
    sf::RenderWindow* getWindow();
    //void setSize
    void init(float *m_CentralClock, StateMashine *stm);
private:
    sf::RenderWindow m_Window;
    StateMashine *stm;
};


