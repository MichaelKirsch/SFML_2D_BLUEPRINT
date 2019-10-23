

class StateMashine {
public:
    StateMashine() {};
    enum class STATES {
        MENU, RUNNING, CHOOSE_MAP, CHAR_BUILDER
    };

    void init(float *m_CentralClock) {};

    STATES getState() { return m_GlobalGameState; };

    void setState(STATES stateToSet) { m_GlobalGameState = stateToSet; };

    ~StateMashine() = default;

private:
    STATES m_GlobalGameState;
};

class Window {
public:
    Window() {};

    //getWindow
    void init(float *m_CentralClock, StateMashine *stm) {};
private:
    StateMashine *stm;
};

class World {
public:
    World() {};

    void init(float *m_CentralClock, StateMashine *stm, Window *window) {};

    ~World() = default;
};

class GUI {
public:
    GUI() {};

    void init(float *m_CentralClock, StateMashine *stm, Window *window, World *world) {};

    ~GUI() = default;
};

class NPCmanager {
public:
    NPCmanager() {};

    void init(float *m_CentralClock, StateMashine *stm, Window *window, World *world) {};

    ~NPCmanager() = default;
};

class Soundmanager {
public:
    Soundmanager() {};

    ~Soundmanager() = default;

    void init(float *m_CentralClock, StateMashine *stm, Window *window, World *world, NPCmanager *npCmanager) {};
};

class Chunkmanager {
public:
    Chunkmanager() {};

    ~Chunkmanager() = default;

    void init(float *m_CentralClock, StateMashine *stm, Window *window, World *world) {};
};


class MainGameManager {
public:
    MainGameManager() {
        m_Statemashine.init(&m_CentralClock);
        m_Window.init(&m_CentralClock, &m_Statemashine);
        m_World.init(&m_CentralClock, &m_Statemashine, &m_Window);
        m_Gui.init(&m_CentralClock, &m_Statemashine, &m_Window, &m_World);
        m_NPCmanager.init(&m_CentralClock, &m_Statemashine, &m_Window, &m_World);
        m_Soundmanager.init(&m_CentralClock, &m_Statemashine, &m_Window, &m_World, &m_NPCmanager);
        m_Chunkmanager.init(&m_CentralClock, &m_Statemashine, &m_Window, &m_World);
    }

    ~MainGameManager() = default;

    void run() {
        //update the states

        //render the stuff

    };
private:
    float m_CentralClock;
    StateMashine m_Statemashine;
    World m_World;
    GUI m_Gui;
    Window m_Window;
    NPCmanager m_NPCmanager;
    Soundmanager m_Soundmanager;
    Chunkmanager m_Chunkmanager;
};



