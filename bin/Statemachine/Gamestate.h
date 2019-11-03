#pragma once

#include "EssentialWindow.h"

class GameState {
public:
    GameState(){};
    void init(EssentialWindow* window,unsigned int framerate = 60 , unsigned int logicrate = 30, unsigned int eventrate =120 )
    {
        this->m_window=window;
        this->eventrate = eventrate;
        this->logicrate = logicrate;
        this->framerate = framerate;
    }

    void run()
    {
        m_elapsed = m_window->m_Clock.restart().asSeconds();
        frame_cl+=m_elapsed;
        logic_cl+=m_elapsed;
        evt_cl+=m_elapsed;
        if(frame_cl>1.0/framerate)
        {
            render();
            frame_cl=0;
        }
        if(logic_cl>1.0/logicrate)
        {
            logic();
            logic_cl=0;
        }
        if(evt_cl>1.0/eventrate)
        {
            handle_events();
            evt_cl=0;
        }
    }

    virtual void handle_events() {};

    virtual void logic() {};

    virtual void render() {};

    virtual ~GameState() = default;

private:
    EssentialWindow* m_window;
    float m_elapsed;
    float frame_cl,logic_cl,evt_cl;
    unsigned int framerate, logicrate,eventrate;
};