

#include "SimpleText.h"

gui::SimpleText::SimpleText(EssentialWindow &es) : m_Essential(es){
    m_TextString = "undefined";
    m_Text.setFillColor(m_Essential.m_GuiStyle.textColor);
    m_Text.setFont(m_Essential.m_GlobFont);
    auto charsize = (m_Essential.m_Window.getSize().y/100)*m_Essential.m_GuiStyle.buttonHeight;
    m_Text.setCharacterSize(charsize);
    refactor();
}

void gui::SimpleText::setText(std::string text) {
    m_TextString = text;
    refactor();
}

void gui::SimpleText::draw() {
    m_Essential.m_Window.draw(m_Text);
}

void gui::SimpleText::refactor() {
    auto charsize = (m_Essential.m_Window.getSize().y/100)*m_Essential.m_GuiStyle.buttonHeight;
    m_Text.setCharacterSize(charsize);
    m_Text.setString(m_TextString);
    m_Text.setFillColor(m_Essential.m_GuiStyle.textColor);
    auto positionInPixels = sf::Vector2f(m_Position.x*(m_Essential.m_Window.getSize().x/100),m_Position.y*(m_Essential.m_Window.getSize().y/100));
    if(isCentered)
    {
        auto getoutline = m_Text.getGlobalBounds();
        positionInPixels = sf::Vector2f(positionInPixels.x-getoutline.width/2,positionInPixels.y-getoutline.height/2);
    }
    m_Text.setPosition(positionInPixels);
}

void gui::SimpleText::setPositionOfCenter(sf::Vector2u pos) {
    m_Position = pos;
    isCentered = true;
    refactor();
}


