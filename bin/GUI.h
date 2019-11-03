#pragma once

#include "Window.h"
#include "TGUI/TGUI.hpp"

class GUI {
public:
    GUI();
    GUI(Window *window);
    void init(Window *window);
    ~GUI() = default;
};

