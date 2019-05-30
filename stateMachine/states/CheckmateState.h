#ifndef STATEMACHINE_CHECKMATESTATE_H_
#define STATEMACHINE_CHECKMATESTATE_H_

#include "../State.h"

class CheckMateState : public State {
    public:
        void goNext(StateMachine *) override;
};

#endif // STATEMACHINE_CHECKMATESTATE_H_