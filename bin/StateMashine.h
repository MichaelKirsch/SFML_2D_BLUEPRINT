#pragma once

class StateMashine {
public:
    StateMashine();
    enum class STATES {
        MENU, RUNNING, CHOOSE_MAP, CHAR_BUILDER
    };

    void init(float *m_CentralClock);

    STATES getState() { return m_GlobalGameState;};

    void setState(STATES stateToSet);

    ~StateMashine() = default;

private:
    STATES m_GlobalGameState;
};


