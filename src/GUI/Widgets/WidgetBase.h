#pragma once

#include "EssentialWindow.h"

namespace gui
{
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
        bool isVisible = true;
        bool isActive = true;
    protected:
        EssentialWindow& m_Essential;
    };
}


