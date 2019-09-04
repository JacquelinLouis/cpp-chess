#ifndef TEST_TEST_H_
#define TEST_TEST_H_

#include <iostream>
#include <assert.h>

#define TEST(name, body)\
class name : public Test {\
    public:\
        name() : Test() {\
            startTest(__func__);\
            runTest();\
            endTest();\
        }\
    private:\
        void runTest() { body }\
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
            genericTrue(expectation, State::EXPECT_FAILED);
        }

        void expectFalse(bool expectation) {
            expectTrue(!expectation);
        }

        template<typename T>
        void expectEquals(T expected, T actual) {
            genericEquals(expected, actual, State::EXPECT_FAILED);
        }

        template<typename T>
        void expectNotEquals(T expected, T actual) {
            genericNotEquals(expected, actual, State::EXPECT_FAILED);
        }

    protected:

        void startTest(const char * name);

        void endTest();

    private:
        enum State {
            SUCCESS,
            EXPECT_FAILED,
            ASSERT_FAILED
        };

        bool genericTrue(bool expectation, State errorState) {
            if (!expectation) {
                m_state = errorState;
                std::cout << "expect " << expectation << " to be " << !expectation << std::endl;
            }
            return expectation;
        }

        template<typename T>
        bool genericEquals(T expected, T actual, State errorState) {
            bool expectation = expected == actual; 
            if (!expectation) {
                m_state = errorState;
                std::cout << "expect " << actual << " to be equal to " << expected << std::endl;
            }
            return expectation;
        }

        template<typename T>
        bool genericNotEquals(T expected, T actual, State errorState) {
            bool expectation = expected != actual; 
            if (!expectation) {
                m_state = errorState;
                std::cout << "expect " << actual << " to be different from " << expected << std::endl;
            }
            return expectation;
        }

        State m_state;
        int m_called;

        static int TEST_NUMBER;
};

#endif // TEST_TEST_H_