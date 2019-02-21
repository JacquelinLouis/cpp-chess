#ifndef TEST_TEST_H_
#define TEST_TEST_H_

#include <iostream>

class Test {
    public:
        Test();
        ~Test();
        void expectCall();
        void call();
        void runExpectation();
        void expectTrue(bool expectation);
        void expectFalse(bool expectation);
        template<typename T>
        void expectEquals(T expected, T actual) {
            cout();
            if (expected != actual) {
                std::cout << FAILED << ": expect " << actual << " to be equal to " << expected << std::endl;
            } else {
                std::cout << SUCCESS << std::endl;
            }
        }

        template<typename T>
        void expectNotEquals(T expected, T actual) {
            cout();
            if (expected == actual) {
                std::cout << FAILED << ": expect " << actual << " to be different from " << expected << std::endl;
            } else {
                std::cout << SUCCESS << std::endl;
            }
        }
        

    private:
        static const char *SUCCESS; 
        static const char *FAILED;
        static int k_testNumber;
        int m_called;

        void cout();
};

#endif // TEST_TEST_H_