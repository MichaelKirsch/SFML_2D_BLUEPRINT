

#include "Menu.h"

gui::Menu::Menu(EssentialWindow* es) : m_Essential(es) {
}

void gui::Menu::draw() {
    for(auto& bu:m_Elements)
    {
        bu.second->draw();
    }
}

void gui::Menu::update() {
    for(auto& bu:m_Elements)
    {
        bu.second->update();
    }
}

void gui::Menu::createMenu(std::string name, std::vector<std::string> buttons) {
    auto screenPercentageUsedByButtonsAndSpaces = m_Essential->m_GuiStyle.buttonHeight*((2*buttons.size())-1);
    auto topAndBottomSpace = 100-screenPercentageUsedByButtonsAndSpaces;
    int middleOfFirstButton = (topAndBottomSpace/2)+(m_Essential->m_GuiStyle.buttonHeight*0.5);
    int index = 0;
    for(auto& bu:buttons)
    {
        sf::Vector2u position = {50,middleOfFirstButton+(2*index*m_Essential->m_GuiStyle.buttonHeight)};
        auto Buffer = new Button(m_Essential,position,bu);
        Buffer->setText(bu);
        Buffer->setPositionOfCenter(position);
        m_Elements.insert(std::make_pair(bu,Buffer));
        index++;
    }
}

bool gui::Menu::getButtonState(std::string buttonName) {
    if(m_Elements.find(buttonName)!=m_Elements.end()) //first check if the name is in the list
    {
        return m_Elements.at(buttonName)->isClicked();
    }
    else
    {
        return false;
    }
}

