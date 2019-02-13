#ifndef TEST_MVC_H_
#define TEST_MVC_H_

class MvcTests {
    public:
        void runAll();

    private:
        void testAddListener();
        void testDifferentsIdentifiers();
        void testRemoveListener();
        void testListenerCall();
};

#endif // TEST_MVC_H_