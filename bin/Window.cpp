//
// Created by micha on 24.10.2019.
//

#include "Window.h"

Window::Window() {

}

sf::RenderWindow *Window::getWindow() {
    return &m_Window;
}

void Window::init(sf::Vector2u resolution) {
    m_Window.setSize(resolution);
}



