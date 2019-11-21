#pragma once

namespace gui
{
class Widget
{
public:
    virtual ~Widget()= default;
    virtual void draw(){};
    virtual void update(){};
    void setActive(bool staus){isActive=staus;};
    bool isVisible = true;
    bool isActive = true;
};
}


