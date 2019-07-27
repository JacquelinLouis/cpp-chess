#ifndef TEST_TEST_H_
#define TEST_TEST_H_

#include <iostream>

#define TEST(name, body)                                    \
class name : private Test {                                 \
    friend void name() {                                    \
        TEST_NUMBER += 1;                                   \
        std::cout << "Test[" << Test::TEST_NUMBER << "] ";  \
        std::cout << __func__ << std::endl;                 \
        body;                                               \
    }                                                       \
};                                                          \

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

        static void expectTrue(bool expectation);
        static void expectFalse(bool expectation);
        template<typename T>
        static void expectEquals(T expected, T actual) {
            cout();
            if (expected != actual) {
                std::cout << FAILED << ": expect " << actual << " to be equal to " << expected << std::endl;
            } else {
                std::cout << SUCCESS << std::endl;
            }
        }

        /*
        template<typename T,
                 typename = typename std::enable_if<std::is_enum<T>::value, bool>::type>
        static void expectEquals(T expected, T actual) {
            expectEquals(static_cast<int>(expected), static_cast<int>(actual)); 
        }
        */

        template<typename T>
        static void expectNotEquals(T expected, T actual) {
            cout();
            if (expected == actual) {
                std::cout << FAILED << ": expect " << actual << " to be different from " << expected << std::endl;
            } else {
                std::cout << SUCCESS << std::endl;
            }
        }
        
        static int TEST_NUMBER;

    private:
        static const char *SUCCESS; 
        static const char *FAILED;
        int m_called;

        static void cout();
};

#endif // TEST_TEST_H_