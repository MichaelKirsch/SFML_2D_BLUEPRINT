

#include "Button.h"

gui::Button::Button(EssentialWindow& es, sf::Vector2u pos, std::string text, unsigned int width) : Widget(es){
    this->m_Style = m_Essential.m_GuiStyle;
    this->m_Size = {width,m_Style.buttonHeight};
    this->isVisible = true;
    this->m_Pos = pos;
    this->isCentered = false;
    this->isActive = true;
    this->m_Text.setFont(es.m_GlobFont);
    this->mouseOver = false;
    refactor();
}

void gui::Button::setFillColor(sf::Color newCol) {
    m_Style.defaultColor = newCol;
    m_MouseOver = sf::Color(m_Style.defaultColor.r/2,m_Style.defaultColor.g/2,m_Style.defaultColor.b/2);
    refactor();
}

void gui::Button::update() {
    auto bounds = m_Rect.getGlobalBounds();
    auto mouse = m_Essential.m_Mouse.getPosition(m_Essential.m_Window);
    if(mouse.x>bounds.left&&mouse.x<bounds.left+bounds.width&&mouse.y>bounds.top&&mouse.y<bounds.top+bounds.height&&isActive)
    {
        //mouse is inside the button
        mouseOver = true;
        m_Rect.setFillColor(m_MouseOver);
        m_Text.setFillColor(m_Style.textColor);
    }
    else if(!isActive)
    {
        mouseOver = false;
        m_Rect.setFillColor(m_Style.inactiveColor);
        m_Text.setFillColor(m_Style.textColorInactive);
    }
    else
    {
        mouseOver = false;
        m_Rect.setFillColor(m_Style.defaultColor);
        m_Text.setFillColor(m_Style.textColor);
    }
}

bool gui::Button::isClicked() {
    update();
    if(isVisible&&isActive)
        return (mouseOver&&m_Essential.m_Mouse.isButtonPressed(sf::Mouse::Left));
    return false;
}

void gui::Button::draw() {
    m_Essential.m_Window.draw(m_Rect);
    m_Essential.m_Window.draw(m_Text);
}

void gui::Button::setSize(int newSize) {
    this->m_Style.buttonHeight = newSize;
    refactor();
}

void gui::Button::refactor() {
    m_Text.setFillColor(m_Style.textColor);
    auto windowSize = m_Essential.m_Window.getSize();
    auto sizeInPixels = sf::Vector2f(m_Style.buttonHeight*(windowSize.x/100.f),m_Style.buttonHeight*(windowSize.y/100.f));
    auto positionInPixels =  sf::Vector2f(m_Pos.x*(windowSize.x/100.f),m_Pos.y*(windowSize.y/100.f));
    m_Text.setCharacterSize(sizeInPixels.y); //textsize will be calculated by the rect size
    auto char_count = m_Text.getGlobalBounds().width+m_Text.getLineSpacing();
    m_Rect.setSize(sf::Vector2f(char_count,sizeInPixels.y*1.61));
    auto rectSize = m_Rect.getGlobalBounds();
    if(isCentered)
    {
        positionInPixels = sf::Vector2f(positionInPixels.x-(rectSize.width/2.0),positionInPixels.y-(rectSize.height/2.0));

    }
    m_Rect.setPosition(positionInPixels);
    m_Text.setPosition(positionInPixels);
}

void gui::Button::setPositionOfTopLeft(sf::Vector2u pos) {
    m_Pos = pos;
    isCentered = false;
    refactor();
}

void gui::Button::setPositionOfCenter(sf::Vector2u pos) {
    m_Pos = pos;
    isCentered = true;
    refactor();
}

gui::Button::~Button() {
}

std::string gui::Button::getText() {
    return m_Text.getString();
}

void gui::Button::setText(std::string inString) {
    m_Text.setString(inString);
    refactor();
}

void gui::Button::setTextColor(sf::Color newColor) {
    m_Style.textColor = newColor;
    refactor();
}

void gui::Button::setVisible(bool vis) {
    isVisible = vis;
}