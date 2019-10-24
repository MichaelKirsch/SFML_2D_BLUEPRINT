#pragma once

#include "StateMashine.h"
#include "Window.h"
#include "World.h"
#include "TGUI/TGUI.hpp"

class GUI {
public:
    GUI();

    void init(float *m_CentralClock, StateMashine *stm, Window *window, World *world);

    ~GUI() = default;
};

