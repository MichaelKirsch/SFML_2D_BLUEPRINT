

#include "GUI.h"

gui::Button::Button(EssentialWindow *es, sf::Vector2u pos, std::string text, sf::Vector2u size) : m_Essential(es){
    this->m_Size = size;
    this->m_Pos = pos;
    this->m_Text = text;
    this->mouseOver = false;
    refactor();
}

void gui::Button::setFillColor(sf::Color newCol) {
    m_FillColor = newCol;
    m_MouseOver = sf::Color(m_FillColor.r/2,m_FillColor.g/2,m_FillColor.b/2);
}

void gui::Button::update() {
    auto bounds = m_Rect.getGlobalBounds();
    auto mouse = m_Essential->m_Mouse.getPosition(m_Essential->m_Window);
    if(mouse.x>bounds.left&&mouse.x<bounds.left+bounds.width&&mouse.y>bounds.top&&mouse.y<bounds.top+bounds.height)
    {
        //mouse is inside the button
        mouseOver = true;
        m_Rect.setFillColor(m_MouseOver);
    }
    else
    {
        mouseOver = false;
        m_Rect.setFillColor(m_FillColor);
    }
}

bool gui::Button::isClicked() {
    //update(); //maybe that will prevent some bugs i dont know
    return (mouseOver&&m_Essential->m_Mouse.isButtonPressed(sf::Mouse::Left));
}

void gui::Button::draw() {
    m_Essential->m_Window.draw(m_Rect);
}

void gui::Button::setSize(sf::Vector2u newSize) {
    this->m_Size = newSize;
    refactor();
}

void gui::Button::refactor() {
    //textsize is determined by the rectsize
    auto windowSize = m_Essential->m_Window.getSize();
    auto sizeInPixels = sf::Vector2f(m_Size.x*(windowSize.x/100.f),m_Size.y*(windowSize.y/100.f));
    auto positionInPixels =  sf::Vector2f(m_Pos.x*(windowSize.x/100.f),m_Pos.y*(windowSize.y/100.f));
    m_Rect.setSize(sizeInPixels);
    m_Rect.setPosition(positionInPixels);
}

void gui::Button::setPositionOfTopLeft(sf::Vector2u pos) {
    m_Pos = pos;
    refactor();
}

void gui::Button::setPositionOfCenter(sf::Vector2u pos) {
    //TODO: here we will need some checks if the button is still inside the window bounds
    //m_Pos = sf::Vector2u(pos.x-m_Size.x/2,pos.y-m_Size.y/2);
    refactor();
}

void gui::Button::setEssentialWindow(EssentialWindow *in) {
    m_Essential = in;
    refactor();
}

gui::Button::~Button() {
}

std::string gui::Button::getText() {
    return m_Text;
}

void gui::CommoRose::refactor() {
    m_MainCircle.setPointCount(m_Buttons.size());
    for (auto bu:m_Buttons) {

    }
}
