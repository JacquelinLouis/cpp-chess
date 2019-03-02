#include "PlayState.h"

#include "CheckmateState.h"

void Playstate::goNext(StateMachine * stateMachine) {
    if (stateMachine) {
        State currentState = stateMachine->getCurrentState();
        if (currentState.getType() == StateTypeModel::PLAYSTATE) {
            stateMachine->setState(CheckMateState());
        }
    }
}