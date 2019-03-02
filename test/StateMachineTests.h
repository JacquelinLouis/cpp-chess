#ifndef TEST_STATEMACHINETESTS_H_
#define TEST_STATEMACHINETESTS_H_

#include "TestClass.h"

class StateMachineTests : public TestClass {
    public:
        void runAll() override;

    private:
        void testDefaultState();
        void testSetState();
        void testSwitchFromPlayToCheckmateState();
};

#endif // TEST_STATEMACHINETESTS_H_