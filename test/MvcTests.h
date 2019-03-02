#ifndef TEST_MVC_H_
#define TEST_MVC_H_

#include "TestClass.h"

class MvcTests : public TestClass {
    public:
        void runAll() override;
    private:
        void testAddListener();
        void testDifferentsIdentifiers();
        void testRemoveListener();
        void testListenerCall();
};

#endif // TEST_MVC_H_