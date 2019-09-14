#include "Test.h"

#include <iostream>

int Test::TEST_NUMBER = 0;

Test::Test() :
    m_called(0),
    m_testFailed(false)
{}

void Test::startTest(const char * name) {
    TEST_NUMBER += 1;
    std::cout << "Test[" << Test::TEST_NUMBER << "] " << name << std::endl;
}

void Test::runTest(const char * name, std::function<void()> body) {
    startTest(name);
    try {
        body();
    } catch (std::exception e) {
        std::cout << "Debug" << std::endl;
    }
    endTest();
}

void Test::endTest() {
    runExpectation();
    std::cout << "    [" << TEST_NUMBER << ']' <<
            (m_testFailed < 1 ? " SUCCESS" : " FAILED") << std::endl;
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
