#include "src/Statemachine/StateMachine.h"

int main()
{
    StateMachine stm{"Ceasar-2D",60,50,50};
    stm.dispatch(STATES::EXITING);
}

