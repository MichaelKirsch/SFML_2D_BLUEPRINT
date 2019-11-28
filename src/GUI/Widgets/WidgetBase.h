#pragma once

namespace gui
{
class Widget
{
public:
    virtual ~Widget()= default;
    virtual void draw(){};
    virtual void update(){};
    void setActive(bool status){isActive=status;isVisible=status;};

    bool isVisible = true;
    bool isActive = true;
};
}


