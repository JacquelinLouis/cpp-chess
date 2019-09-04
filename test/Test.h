#ifndef TEST_TEST_H_
#define TEST_TEST_H_

#include <iostream>

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

        void assertTrue(bool expectation) {
            genericTrue(expectation, State::ASSERT_FAILED);
            exit(EXIT_FAILURE);
        }

        void expectFalse(bool expectation) {
            expectTrue(!expectation);
        }

        void assertFalse(bool expectation) {
            assertTrue(!expectation);
            exit(EXIT_FAILURE);
        }

        template<typename T>
        void expectEquals(T expected, T actual) {
            genericEquals(expected, actual, State::EXPECT_FAILED);
        }

        template<typename T>
        void assertEquals(T expected, T actual) {
            genericEquals(expected, actual, State::ASSERT_FAILED);
            exit(EXIT_FAILURE);
        }

        template<typename T>
        void expectNotEquals(T expected, T actual) {
            genericNotEquals(expected, actual, State::EXPECT_FAILED);
        }

        template<typename T>
        void assertNotEquals(T expected, T actual) {
            genericNotEquals(expected, actual, State::ASSERT_FAILED);
            exit(EXIT_FAILURE);
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

        void genericTrue(bool expectation, State errorState) {
            if (!expectation) {
                m_state = errorState;
                std::cout << "expect " << expectation << " to be " << !expectation << std::endl;
            }
        }

        template<typename T>
        void genericEquals(T expected, T actual, State errorState) {
            if (expected == actual) {
                m_state = errorState;
                std::cout << "expect " << actual << " to be equal to " << expected << std::endl;
            }
        }

        template<typename T>
        void genericNotEquals(T expected, T actual, State errorState) {
            if (expected != actual) {
                m_state = errorState;
                std::cout << "expect " << actual << " to be different from " << expected << std::endl;
            }
        }

        State m_state;
        int m_called;

        static int TEST_NUMBER;
};

#endif // TEST_TEST_H_