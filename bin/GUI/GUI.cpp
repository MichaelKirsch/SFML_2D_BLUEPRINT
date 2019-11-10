//
// Created by micha on 24.10.2019.
//

#include "GUI.h"

GameGui::GUI_Manager::GUI_Manager(EssentialWindow &window) : m_Window(window){
    std::string fontpath = "";
    fontpath+="Sandwich.ttf";
}

void GameGui::GUI_Manager::draw_and_check_mouseover() {
    for(auto& el:m_Elements)
    {
        if(el->mouseOver())
        {

        }

        el->draw();
    }
}


void GameGui::Button::draw() {
    //GUI_Element::draw();
}

bool GameGui::GUI_Element::mouseOver() {
    return false;
}

void GameGui::GUI_Style::loadStyleSheet() {

}
