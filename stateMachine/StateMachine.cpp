#include "StateMachine.h"

StateMachine::StateMachine(
        std::function<void(StateTypeModel, ColorModel)> stateUpdatedCallback) :
    m_currentState(StateTypeModel::PLAYSTATE, ColorModel::WHITE),
    m_stateUpdated(stateUpdatedCallback)
{}

State StateMachine::getCurrentState() const {
    return m_currentState;
}

void StateMachine::goNextState() {
    m_currentState.goNext(this);
}

void StateMachine::setState(State state) {
    m_currentState = state;
    m_stateUpdated(m_currentState.getType(), m_currentState.getColor());
}
