#include "StateMachine.h"
#include "states/PlayState.h"

StateMachine::StateMachine(std::function<void()> stateUpdatedCallback) :
    m_currentState(new Playstate())
{}

State * StateMachine::getCurrentState() const {
    return m_currentState;
}

void StateMachine::goNextState() {
    if (m_currentState == nullptr)
        return;
    m_currentState->goNext(this);
}

void StateMachine::setState(State * state) {
    delete m_currentState;
    m_currentState = state;
    notify();
}
