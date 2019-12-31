

#include "GuiManager.h"

gui::Button* gui::Manager::addButton() {
    auto *newButton = new Button(m_Essential);
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
    auto *newButton = new Menu(m_Essential);
    m_Elements.emplace_back(newButton);
    return newButton;
}

gui::SimpleText *gui::Manager::addSimpleText() {
    auto *newElement = new SimpleText(m_Essential);
    m_Elements.emplace_back(newElement);
    return newElement;
}

gui::Button *gui::Manager::addButton(std::string text,sf::Vector2f pos) {
    auto *newElement = new Button(m_Essential);
    newElement->setText(text);
    newElement->setPositionOfTopLeft({static_cast<unsigned int>(pos.x),static_cast<unsigned int>(pos.y)});
    m_Elements.emplace_back(newElement);
    return newElement;
}

gui::Button *gui::Manager::addButtonCentered(std::string text, sf::Vector2u posCenter) {
    auto *newElement = new Button(m_Essential);
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

gui::progressBar *gui::Manager::addProgressBar(int value, int max_value) {
    auto *newElement = new progressBar(m_Essential);
    newElement->setValue(value);
    newElement->setMaxValue(max_value);
    m_Elements.emplace_back(newElement);
    return newElement;
}

gui::ToggleButton *gui::Manager::addToggleButton(std::string name = "default",sf::Vector2f pos={10,10}, bool val= false) {
    auto *newElement = new ToggleButton(m_Essential);
    newElement->setStatus(val);
    newElement->setName(name);
    newElement->setPosition(pos);
    m_Elements.emplace_back(newElement);
    return newElement;
}

gui::SmipleChoosingMenu *gui::Manager::addSimpleChoosingMenu(std::string b_left, std::string b_right, std::vector<std::string> options) {
    auto *newElement = new SmipleChoosingMenu(m_Essential,b_left,b_right,options);
    m_Elements.emplace_back(newElement);
    return newElement;
}
