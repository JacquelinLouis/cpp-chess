#include "Test.h"

#include <iostream>

int Test::TEST_NUMBER = 0;

Test::Test() :
    m_success(true),
    m_called(0)
{
    TEST_NUMBER += 1;
    std::cout << "Test[" << Test::TEST_NUMBER << "] ";
}

Test::~Test() {
    runExpectation();
    std::cout << (m_success ? "SUCCESS" : "FAILED") << std::endl;   \
}

void Test::expectCall() {
    m_called += 1;
}

void Test::raiseCall() {
    m_called -= 1;
}

void Test::runExpectation() {
    if (m_called != 0) {
        m_success = false;
        std::cout << "expect " << m_called << " call" << std::endl;
    }
}
