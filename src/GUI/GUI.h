

#pragma once
#include <iostream>
#include "../Statemachine/EssentialWindow.h"
#include <string>
#include <experimental/filesystem>
#include <list>

namespace gui
{
    class Widget
    {
    public:
        virtual ~Widget()= default;
        virtual void draw(){};
        virtual void update(){};
        bool isVisible = true;
    };

    class Button : public Widget
    {
    //the button position is always the top left. but you can receive the center
    public:
        Button(EssentialWindow* es, sf::Vector2u pos = {0,0}, std::string text = "not configured yet", unsigned int width = 1);
        ~Button();
        void draw();
        void setVisible(bool visibility);
        void setEssentialWindow(EssentialWindow* );
        void setSize(sf::Vector2u);
        void setTextColor(sf::Color newColor);
        void setFillColor(sf::Color newColor);
        void update();
        void setText(std::string);
        std::string getText();
        bool isClicked();
        void setPositionOfTopLeft(sf::Vector2u pos);
        void setPositionOfCenter(sf::Vector2u pos);
    private:
        sf::Text m_Text;
        void refactor();//this function will be called when there is any change in size color or anything like that
        bool mouseOver;
        sf::RectangleShape m_Rect;
        EssentialWindow* m_Essential;
        sf::Vector2u m_Size,m_Pos = {0,0};
        sf::Color m_FillColor,m_MouseOver,m_TextCol;
    };

    class Menu : public Widget
    {
    public:
        Menu(EssentialWindow* es) : m_Essential(es) {};
        ~Menu() = default;
        bool getButtonState(std::string buttonName);
        void createMenu(std::vector<std::string>);
        void setSizeofButtons(unsigned int size);
        void update();
        void draw();
    private:
        EssentialWindow* m_Essential;
        unsigned int m_buttonSize;
        std::map<std::string,std::unique_ptr<gui::Button>> m_Buttons;
    };

    class Manager
    {
    public:
        Manager(EssentialWindow& es):m_Essential(es) {};
        void draw();
        void update();
        ~Manager()=default;
        gui::Button* addButton();
        gui::Menu* addMenu();
    private:
        EssentialWindow& m_Essential;
        std::vector<std::unique_ptr<Widget>> m_Elements;
    };

}


