#pragma once

#include "StateMashine.h"
#include "Window.h"
#include "World.h"
#include ""

class GUI {
public:
    GUI();

    void init(float *m_CentralClock, StateMashine *stm, Window *window, World *world);

    ~GUI() = default;
};

