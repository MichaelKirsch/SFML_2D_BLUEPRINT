#include "src/Statemachine/StateMachine.h"

int main()
{
    StateMachine stm{"Ceasar-2D",60,30,100, true};
    stm.dispatch(STATES::MENU);
}

