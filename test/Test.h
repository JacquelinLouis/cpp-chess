#ifndef TEST_TEST_H_
#define TEST_TEST_H_

#include <iostream>
#include <functional>

#define TEST(name, body)\
class name : public Test {\
    public:\
        name() : Test() {\
            startTest(__func__);\
            runTest(__func__, [this]() { body });\
            endTest();\
        }\
};

class Test {
    public:
        Test();

        /**
         * @brief Call expectation, when adding this to code, if {@link Test::raiseCall}
         * method is not runned before {@link Test::runExpectation} is called,
         * this last one return an error.
         */
        void expectCall();
        /**
         * @brief Must be called when a {@link Test::expectCall} is added.
         */
        void raiseCall();
        /**
         * @brief Check that all expectedCall/call methods have matched.
         * Else raise an error.
         */
        void runExpectation();

        void expectTrue(bool expectation) {
            genericEquals(expectation, true);
        }

        void assertTrue(bool expectation) {
            if (!genericEquals(expectation, true)) { throw new std::exception(); }
        }

        void assertFalse(bool expectation) {
            if (!genericEquals(expectation, false)) { throw new std::exception(); }
        }

        template<typename T>
        void assertEquals(T expected, T actual) {
            if (!genericEquals(expected, actual)) { throw new std::exception(); }
        }

        template<typename T>
        void assertNotEquals(T expected, T actual) {
            if (!genericNotEquals(expected, actual)) { throw new std::exception(); }
        }

        void expectFalse(bool expectation) {
            expectTrue(!expectation);
        }

        template<typename T>
        void expectEquals(T expected, T actual) {
            genericEquals(expected, actual);
        }

        template<typename T>
        void expectNotEquals(T expected, T actual) {
            genericNotEquals(expected, actual);
        }

    protected:

        void startTest(const char * name);

        void endTest() {
            runExpectation();
            std::cout << (TEST_NUMBER_ERROR < 1 ? "SUCCESS" : "FAILED") << std::endl;
        }

        void runTest(const char * name, std::function<void()> body) {
            startTest(name);
            try {
                body();
            } catch (std::exception e) {
                std::cout << "Debug" << std::endl;
            }
            endTest();
        }

    private:

        template<typename T>
        bool genericEquals(T expected, T actual) {
            bool expectation = expected == actual; 
            if (!expectation) {
                TEST_NUMBER_ERROR += 1;
                std::cout << "expect " << actual << " to be equal to " << expected << std::endl;
            }
            return expectation;
        }

        template<typename T>
        bool genericNotEquals(T expected, T actual) {
            bool expectation = expected != actual; 
            if (!expectation) {
                TEST_NUMBER_ERROR += 1;
                std::cout << "expect " << actual << " to be different from " << expected << std::endl;
            }
            return expectation;
        }

        int m_called;

        static int TEST_NUMBER;
        static int TEST_NUMBER_ERROR;
};

#endif // TEST_TEST_H_