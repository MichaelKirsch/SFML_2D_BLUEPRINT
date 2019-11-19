

#include "GuiManager.h"

gui::Button* gui::Manager::addButton() {
    auto *newButton = new Button(&m_Essential);
    m_Elements.emplace_back(newButton);
    return newButton;
}

void gui::Manager::draw() {
    for(auto& el:m_Elements)
    {
        if(el->isVisible)
            el->draw();
    }
}

void gui::Manager::update() {
    for(auto& el:m_Elements)
    {
        el->update();
    }
}

gui::Menu *gui::Manager::addMenu() {
    auto *newButton = new Menu(&m_Essential);
    m_Elements.emplace_back(newButton);
    return newButton;
}

gui::SimpleText *gui::Manager::addSimpleText() {
    auto *newElement = new SimpleText(m_Essential);
    m_Elements.emplace_back(newElement);
    return newElement;
}
