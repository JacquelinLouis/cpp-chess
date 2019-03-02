#ifndef STATEMACHINE_STATE_H_
#define STATEMACHINE_STATE_H_

#include "StateMachine.h"

#include "../model/StateTypeModel.h"
#include "../model/ColorModel.h"

class State {
    public:
        State(StateTypeModel type);
        virtual void goNext(StateMachine *);

        StateTypeModel getType() const;

    private:
        StateTypeModel m_stateTypeModel;
};

#endif // STATEMACHINE_STATE_H_