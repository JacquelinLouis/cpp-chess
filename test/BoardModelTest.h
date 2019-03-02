#ifndef TEST_BOARDMODELTEST_H_
#define TEST_BOARDMODELTEST_H_

#include "TestClass.h"
#include "Test.h"

class BoardModelTest : public TestClass {
    public:
        void runAll() override;

    private:
        void testInitialize();
        void testKings();
        void testQueens();
        void testRooks();
        void testPawns();
        void testKnights();
        void testBishops();
};

#endif // TEST_BOARDMODELTEST_H_