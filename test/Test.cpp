#include "Test.h"

#include <iostream>

const char *Test::SUCCESS = "SUCCESS";
const char *Test::FAILED = "FAILED"; 

Test::Test() :
    m_called(0)
{}

Test::~Test() {
    runExpectation();
}

void Test::expectCall() {
    m_called += 1;
}

void Test::runExpectation() {
    if (m_called != 0) {
        std::cout << FAILED << ": expect " << m_called << " call" << std::endl;
    } else {
        std::cout << SUCCESS << std::endl;
    }
}

void Test::expectTrue(bool expectation) {
    if (!expectation) {
        std::cout << FAILED << ": expect " << expectation << " call" << std::endl;
    } else {
        std::cout << SUCCESS << std::endl;
    } 
}