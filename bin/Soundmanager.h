#pragma once

#include "StateMashine.h"
#include "Window.h"
#include "World.h"
#include "Game.h"

class Soundmanager {
public:
    Soundmanager();

    ~Soundmanager() = default;

    void init(float *m_CentralClock, StateMashine *stm, Window *window, World *world, NPCmanager *npCmanager);
};


