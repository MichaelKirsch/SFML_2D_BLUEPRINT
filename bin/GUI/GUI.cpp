//
// Created by micha on 24.10.2019.
//

#include "GUI.h"

GameGui::Button::Button()
{
    std::string pa = std::experimental::filesystem::current_path().parent_path().string();
    pa+="/data/Font/arial.ttf";
    m_Text.setString("Hello World");
    m_Font.loadFromFile(pa);
    m_Text.setFont(m_Font);
    m_Text.setPosition(100,199);
    m_Text.setCharacterSize(30);
    m_Text.setFillColor(textcol);
    sf::FloatRect bounds = m_Text.getLocalBounds();
    m_Rect.setSize(sf::Vector2f(bounds.width,m_Text.getCharacterSize()));
    m_Rect.setPosition(m_Text.getPosition());
    m_Rect.setFillColor(rectCol);
}

void GameGui::Button::draw() {
    es->m_Window.draw(m_Rect);
    es->m_Window.draw(m_Text);
}

bool GameGui::Button::mouseover() {

    auto mousepos = es->m_Mouse.getPosition(es->m_Window);
    auto pos = m_Text.getPosition();
    auto bounds = m_Rect.getLocalBounds();
    if(mousepos.x>pos.x&&mousepos.x<(pos.x+bounds.width) && mousepos.y>pos.y && mousepos.y<(pos.y+bounds.height))
    {
        m_Rect.setFillColor(moc);
        return true;
    }
    else
    {
        m_Rect.setFillColor(defa);
        return false;
    }
}

void GameGui::Button::setWindow(EssentialWindow *es) {
    this->es = es;
}
