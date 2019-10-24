#pragma once

#include "StateMashine.h"
#include "World.h"
#include "Window.h"

class Chunkmanager {
public:
    Chunkmanager();

    ~Chunkmanager() = default;

    void init(float *m_CentralClock, StateMashine *stm, Window *window, World *world);
};

