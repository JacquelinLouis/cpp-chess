#ifndef STATE_MACHINE_STATE_MACHINE_H_
#define STATE_MACHINE_STATE_MACHINE_H_


#include<functional>

#include "../model/StateTypeModel.h"
#include "../model/ColorModel.h"
#include "State.h"

class StateMachine {
    public:
        StateMachine(std::function<void(StateTypeModel, ColorModel)>);
        ~StateMachine();
        State getCurrentState() const;
        void goNextState();
        void setState(State);

    private:
        State m_currentState;
        std::function<void(StateTypeModel, ColorModel)> m_stateUpdated;
};

#endif // STATE_MACHINE_STATE_MACHINE_H_