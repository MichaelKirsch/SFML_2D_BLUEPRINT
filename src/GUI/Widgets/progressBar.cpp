//
// Created by micha on 25.12.2019.
//

#include "progressBar.h"

void gui::progressBar::update() {

}

void gui::progressBar::draw() {
    m_Essential.m_Window.draw(m_backgroundShape);
    m_Essential.m_Window.draw(m_progressShape);
    if(m_textIsShown)
        m_Essential.m_Window.draw(valueText);
}

void gui::progressBar::refactor() {
    valueText.setFont(m_Essential.m_GlobFont);
    valueText.setFillColor(sf::Color::White);
    valueText.setString(std::to_string(m_value));
    m_backgroundShape.setSize(m_Essential.fromPercentageToScreenFloat(m_size));

    if(m_orientation == ORIENTATION::HORIZONTAL)
    {
        auto sizexofbackground = m_backgroundShape.getSize().x;
        float size_bar = sizexofbackground*((1.0f/m_maxValue)*m_value);
        m_progressShape.setSize({size_bar,m_backgroundShape.getSize().y});
    }
    if(m_orientation==ORIENTATION::VERTICAL)
    {
        auto sizeYofbackground = m_backgroundShape.getSize().y;
        float size_bar = sizeYofbackground*((1.0f/m_maxValue)*m_value);
        m_progressShape.setSize({m_backgroundShape.getSize().x,m_backgroundShape.getSize().y-size_bar});
    }

    m_backgroundShape.setFillColor(m_backgroundColor);
    m_progressShape.setFillColor(m_progressColor);
    valueText.setCharacterSize(m_backgroundShape.getSize().y);
    auto pos_pix = m_Essential.getPixelValues(m_position);
    sf::Vector2f pos_left_upper = {pos_pix.x-(m_backgroundShape.getSize().x/2.f),pos_pix.y-(m_backgroundShape.getSize().y/2.f)};


    m_progressShape.setPosition(pos_left_upper);
    m_backgroundShape.setPosition(pos_left_upper);
    valueText.setPosition(pos_left_upper);
}

gui::progressBar::progressBar(EssentialWindow &m_es) : Widget(m_es){
    refactor();
}

void gui::progressBar::setPosition(sf::Vector2f pos) {
    m_position = pos;
    refactor();
}


