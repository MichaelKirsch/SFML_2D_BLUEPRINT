

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

gui::Button *gui::Manager::addButton(std::string text) {
    auto *newElement = new Button(&m_Essential);
    newElement->setText(text);
    m_Elements.emplace_back(newElement);
    return newElement;
}

gui::Button *gui::Manager::addButtonCentered(std::string text, sf::Vector2u posCenter) {
    auto *newElement = new Button(&m_Essential);
    newElement->setText(text);
    newElement->setPositionOfCenter(posCenter);
    m_Elements.emplace_back(newElement);
    return newElement;
}

gui::SimpleText *gui::Manager::addSimpleText(std::string text) {
    auto *newElement = new SimpleText(m_Essential);
    newElement->setText(text);
    m_Elements.emplace_back(newElement);
    return newElement;
}

gui::SimpleText *gui::Manager::addSimpleTextCentered(std::string text , sf::Vector2u pos) {
    auto *newElement = new SimpleText(m_Essential);
    newElement->setText(text);
    newElement->setPositionOfCenter(pos);
    m_Elements.emplace_back(newElement);
    return newElement;
}
