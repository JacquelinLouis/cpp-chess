#ifndef TEST_TEST_H_
#define TEST_TEST_H_

#include <iostream>

#define TEST(name, body)                                                    \
class name : public Test {                                                  \
    public:                                                                 \
        name() {                                                            \
            std::cout << __func__ << std::endl;                             \
            { body; }                                                       \
        }                                                                   \
};                                                                          \

class Test {
    public:
        Test();
        ~Test();

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
            if (!expectation) {
                m_success = false;
                std::cout << "expect " << expectation << " to be " << !expectation << std::endl;
            } 
        }

        void expectFalse(bool expectation) {
            expectTrue(!expectation);
        }

        template<typename T>
        void expectEquals(T expected, T actual) {
            if (expected != actual) {
                m_success = false;
                std::cout << "expect " << actual << " to be equal to " << expected << std::endl;
            }
        }

        template<typename T>
        void expectNotEquals(T expected, T actual) {
            if (expected == actual) {
                m_success = false;
                std::cout << "expect " << actual << " to be different from " << expected << std::endl;
            }
        }
        
        bool m_success;

    private:
        int m_called;

        static int TEST_NUMBER;
};

#endif // TEST_TEST_H_