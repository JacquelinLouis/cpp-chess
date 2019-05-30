#ifndef STATE_MACHINE_STATE_MACHINE_H_
#define STATE_MACHINE_STATE_MACHINE_H_

#include<functional>

#include "../mvc/Notifier.h"
#include "State.h"

class State;

/**
 * @brief State machine to store and get the current play state.
 */
class StateMachine : Notifier {
    public:
        StateMachine(std::function<void()> stateUpdatedCallback);
        State * getCurrentState() const;
        void goNextState();
        void setState(State * state);

    private:
        State * m_currentState;
};

#endif // STATE_MACHINE_STATE_MACHINE_H_