#include "src/Statemachine/StateMachine.h"
#include "Serialization.h"

int main()
{

    StateMachine stm{"Ceasar-2D","default.json"};
    stm.dispatch(STATES::MENU);
}

