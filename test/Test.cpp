#include "Test.h"

#include <iostream>

int Test::TEST_NUMBER = 0;
int Test::TEST_NUMBER_ERROR = 0;

Test::Test() :
    m_called(0)
{}

void Test::startTest(const char * name) {
    TEST_NUMBER += 1;
    std::cout << "Test[" << Test::TEST_NUMBER << "] " << name << std::endl;
}

void Test::expectCall() {
    m_called += 1;
}

void Test::raiseCall() {
    m_called -= 1;
}

void Test::runExpectation() {
    if (m_called != 0) {
        std::cout << "expect " << m_called << " call" << std::endl;
    }
}
