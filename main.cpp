#include "src/Statemachine/StateMachine.h"

int main()
{
    StateMachine stm{"Olympus","default.profile"};
    stm.dispatch(STATES::MENU);
}

