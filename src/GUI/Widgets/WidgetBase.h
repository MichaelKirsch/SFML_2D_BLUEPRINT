#pragma once

#include "EssentialWindow.h"

namespace gui
{
    enum class ORIENTATION
    {
        VERTICAL,HORIZONTAL
    };

    enum class SNAPPING_TARGET
    {
        SCREEN,WORLD
    };
    class Widget
    {
    public:
        Widget(EssentialWindow& es):m_Essential(es){}
        virtual ~Widget()= default;
        virtual void draw(){};
        virtual void update(){};
        virtual void refactor(){};
        void setActive(bool status){isActive=status;isVisible=status;};
        Style m_Style;
        SNAPPING_TARGET m_snappedTo;
        virtual void setPositionScreenPercent(sf::Vector2i newPos){positionInScreenPercent=newPos;};
        sf::Vector2i positionInScreenPercent={10,10};
        sf::Vector2f getPixelPosition(){return {static_cast<float>(positionInScreenPercent.x*(m_Essential.m_Window.getSize().x*0.01f)),static_cast<float>(positionInScreenPercent.y*(m_Essential.m_Window.getSize().y*0.01f))};};
        int getTextHeightOfStyle(){ return m_Essential.m_GuiStyle.buttonHeight*(m_Essential.m_Window.getSize().y*0.01);};
        bool isVisible = true;
        bool isActive = true;
    protected:
        EssentialWindow& m_Essential;
    };
}


