#ifndef STATEMACHINE_STATE_H_
#define STATEMACHINE_STATE_H_

#include "StateMachine.h"

#include "../model/PieceModel.h"

class StateMachine;

class State {
    public:
        virtual ~State();
        virtual void goNext(StateMachine *) = 0;
};

#endif // STATEMACHINE_STATE_H_