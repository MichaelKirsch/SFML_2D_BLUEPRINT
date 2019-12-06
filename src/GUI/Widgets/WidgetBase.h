#pragma once

#include "EssentialWindow.h"

namespace gui
{
class Widget
{
public:
    virtual ~Widget()= default;
    virtual void draw(){};
    virtual void update(){};
    void setActive(bool status){isActive=status;isVisible=status;};
    Style m_Style;
    bool isVisible = true;
    bool isActive = true;
};
}


