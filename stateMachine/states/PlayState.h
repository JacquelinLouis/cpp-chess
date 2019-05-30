#ifndef STATE_MACHINE_PLAYSTATE_H_
#define STATE_MACHINE_PLAYSTATE_H_

#include "../State.h"

class Playstate : public State {
    public:
        void goNext(StateMachine *) override;
};

#endif // STATE_MACHINE_PLAYSTATE_H_