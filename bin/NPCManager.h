#pragma once

#include "StateMashine.h"
#include "Window.h"
#include "World.h"

class NPCmanager {
public:
    NPCmanager();

    void init(float *m_CentralClock, StateMashine *stm, Window *window, World *world);

    ~NPCmanager() = default;
};

