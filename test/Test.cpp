#include "Test.h"

#include <iostream>

int Test::TEST_NUMBER = 0;

Test::Test(const char * name) :
    m_state(State::SUCCESS),
    m_called(0)
{
    TEST_NUMBER += 1;
    std::cout << "Test[" << Test::TEST_NUMBER << "] " << name << std::endl;
}

Test::~Test() {
    runExpectation();
    std::cout << (m_state == State::SUCCESS ? "SUCCESS" : "FAILED") << std::endl;
}

void Test::expectCall() {
    m_called += 1;
}

void Test::raiseCall() {
    m_called -= 1;
}

void Test::runExpectation() {
    if (m_called != 0) {
        m_state = State::EXPECT_FAILED;
        std::cout << "expect " << m_called << " call" << std::endl;
    }
}
