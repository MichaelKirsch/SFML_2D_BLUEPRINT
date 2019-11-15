

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
        virtual ~Widget();
        virtual void draw();
        bool isVisible;
    };

    class Button : public Widget
    {
    //the button position is always the top left. but you can receive the center
    public:
        Button();
        Button(EssentialWindow* es, sf::Vector2u pos = {0,0}, std::string text = "not configured yet", sf::Vector2u size ={5,5});
        ~Button();
        void draw();
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

    class CommoRose : public Widget
    {
    public:
        CommoRose()= default;
        ~CommoRose()=default;
        void addButton(std::string name);
        void releaseButton(int listplace);

    private:
        std::list<Button> m_Buttons;

    };

    class DiamondShapedMenu : public Widget
    {
    public:
        DiamondShapedMenu(){};
    private:
        void refactor();
        sf::RectangleShape m_Diamond;
        EssentialWindow* m_Essential;

    };

    class Manager
    {
    public:
        Manager(){};
        void draw();
        ~Manager()=default;
        gui::Button* addButton();

    private:
        //we need a global style here. this will be responsible for a uniform look
        std::vector<std::unique_ptr<Widget>> m_Elements;
    };

}


