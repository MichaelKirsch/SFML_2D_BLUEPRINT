#pragma once

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
}


