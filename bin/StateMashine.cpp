#include "StateMashine.h"

StateMashine::StateMashine() {

}

void StateMashine::init(float *m_CentralClock) {

}

void StateMashine::setState(StateMashine::STATES stateToSet) {
    m_GlobalGameState = stateToSet;
}
