#pragma once

#include "StateMashine.h"
#include "Window.h"

class World {
public:
    World();

    void init(float *m_CentralClock, StateMashine *stm, Window *window);

    ~World() = default;
};


