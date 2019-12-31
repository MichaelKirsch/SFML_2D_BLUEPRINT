

#include <iostream>
#include "SmipleChoosingMenu.h"

void gui::SmipleChoosingMenu::createMenu(std::string button_left, std::string button_right,
                                         std::vector<std::string> buttons) {
    m_ButtonRight.setText(button_right);
    m_ButtonLeft.setText(button_left);
    m_CurrentOptionText.setFont(m_Essential.m_GlobFont);
    m_CurrentOptionText.setFillColor(m_Essential.m_GuiStyle.textColor);
    m_CurrentOptionText.setCharacterSize(Widget::getTextHeightOfStyle());
    m_Options = buttons;
    refactor();
}

void gui::SmipleChoosingMenu::update() {
    timer+=m_Essential.m_Clock.getElapsedTime().asSeconds();
    m_ButtonLeft.update();
    m_ButtonRight.update();
    if(timer>=0.0005f)
    {
        if(m_ButtonLeft.isClicked())
        {
            m_current_option_position--;
            if(m_current_option_position<=0)
            {
                m_current_option_position=0;
            }
            timer = 0.f;
            refactor();
        }
        if(m_ButtonRight.isClicked())
        {
            m_current_option_position++;
            if(m_current_option_position>(m_Options.size()-1))
            {
                m_current_option_position=m_Options.size()-1;
            }
            timer = 0.f;
            refactor();
        }
    }
}
void gui::SmipleChoosingMenu::appendToMenu(std::vector<std::string> newButtons) {
    m_Options.insert(m_Options.end(),newButtons.begin(),newButtons.end());
}

void gui::SmipleChoosingMenu::refactor() {
    m_ButtonLeft.setTextColor(m_Essential.m_GuiStyle.textColor);
    m_ButtonRight.setTextColor(m_Essential.m_GuiStyle.textColor);
    m_CurrentOptionText.setFont(m_Essential.m_GlobFont);
    m_CurrentOptionText.setFillColor(m_Essential.m_GuiStyle.textColor);
    m_CurrentOptionText.setCharacterSize(Widget::getTextHeightOfStyle());
    m_CurrentOptionText.setString(m_Options[m_current_option_position]);
    m_ButtonLeft.setPositionOfTopLeft({static_cast<unsigned int>(positionInScreenPercent.x),static_cast<unsigned int>(positionInScreenPercent.y)});
    auto globBounds_left_Button = m_ButtonLeft.getGlobalBounds();
    auto space_between = ((globBounds_left_Button.width*2)+m_CurrentOptionText.getGlobalBounds().width)*0.1f;
    m_CurrentOptionText.setPosition({globBounds_left_Button.left+space_between,globBounds_left_Button.top});
    auto width_to_percent = (100.f/m_Essential.m_Window.getSize().x)*((2*space_between)+m_CurrentOptionText.getGlobalBounds().width);
    m_ButtonRight.setPositionOfTopLeft({static_cast<unsigned int>(width_to_percent+positionInScreenPercent.x),static_cast<unsigned int>(positionInScreenPercent.y)});
}

gui::SmipleChoosingMenu::SmipleChoosingMenu(EssentialWindow &es,std::string bleft,std::string bright,std::vector<std::string> options) : Widget(es),m_ButtonLeft(es),m_ButtonRight(es) {
    createMenu(bleft,bright,options);
}

void gui::SmipleChoosingMenu::draw() {
    m_Essential.m_Window.draw(m_CurrentOptionText);
    m_ButtonRight.draw();
    m_ButtonLeft.draw();
}
