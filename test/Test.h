#ifndef TEST_TEST_H_
#define TEST_TEST_H_

class Test {
    public:
        Test();
        ~Test();
        void expectCall();
        void runExpectation();
        void expectTrue(bool expectation);
    private:
        static const char *SUCCESS; 
        static const char *FAILED; 

        int m_called;
};

#endif // TEST_TEST_H_