#pragma once
#include "SFML/Graphics.hpp"

class Window {
public:
    Window();
    sf::RenderWindow* getWindow();
    ~Window()= default;
    void init(sf::Vector2u resolution);
private:
    sf::RenderWindow m_Window;
};


