#pragma once

#include "Statemachine/EssentialWindow.h"
#include <experimental/filesystem>
#include <vector>
#include <string>

namespace GameGui
{

    class GUI_Element : public sf::Drawable
    {
    public:
        GUI_Element(){};
        ~GUI_Element()= default;
        virtual void draw(); //draw the element
        virtual bool mouseOver(); //returns if mouse is over and will change the color of the element to the mouseovercolor
    };

    class Button : public GUI_Element
    {
        Button(){};
        void draw();
        bool gotClicked();
        ~Button() = default;
    };

    class GUI_Manager {
    public:
        GUI_Manager(EssentialWindow& window);
        void draw_and_check_mouseover();
        ~GUI_Manager() = default;
        void addText();
        void addButton();
        void addCommoRose();
        void addLineGraph();
        void addTexturedButton();
        void addButtonList();
    private:
        std::vector<std::unique_ptr<GameGui::GUI_Element>> m_Elements;
        EssentialWindow& m_Window;
        sf::Font m_Font;
    };






}



