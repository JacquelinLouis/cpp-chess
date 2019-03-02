#include "State.h"

State::State(StateTypeModel type) :
    m_stateTypeModel(type),
{}

void State::goNext(StateMachine *) {
    // Default behaviour, do nothing 
}

StateTypeModel State::getType() const {
    return m_stateTypeModel;
}