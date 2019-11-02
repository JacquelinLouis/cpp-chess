#ifndef TEST_TEST_H_
#define TEST_TEST_H_

#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

#define TEST(name, body)\
class name : public Test {\
    public:\
        name() : Test() {\
            runTest(__func__, [this]() { body });\
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
            genericEquals(true, expectation);
        }

        void assertTrue(bool expectation) {
            if (!genericEquals(true, expectation)) { throw new std::exception(); }
        }

        void assertFalse(bool expectation) {
            if (!genericEquals(false, expectation)) { throw new std::exception(); }
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
        void expectUnorderedEquals(std::vector<T> expecteds, std::vector<T> actuals) {
            genericUnorderedEquals(expecteds, actuals);
        }

        template<typename T>
        void expectNotEquals(T expected, T actual) {
            genericNotEquals(expected, actual);
        }

    protected:

        void startTest(const char * name);
        void runTest(const char * name, std::function<void()> body);
        void endTest();

    private:

        template<typename T>
        bool genericEquals(T expected, T actual) {
            bool expectation = expected == actual; 
            if (!expectation) {
                m_testFailed = true;
                std::cout << "         expected " << expected << std::endl << " but is equal to " << actual << std::endl;
            }
            return expectation;
        }

        template<typename T>
        bool genericNotEquals(T expected, T actual) {
            bool expectation = expected != actual; 
            if (!expectation) {
                m_testFailed = true;
                std::cout << "               expect " << expected << std::endl << " to be different from " << actual << std::endl;
            }
            return expectation;
        }

        template<typename T>
        bool genericUnorderedEquals(std::vector<T> expecteds, std::vector<T> actuals) {
            bool unorderedEquals = expecteds.size() == actuals.size();
            if (unorderedEquals) {
                std::vector<T> checkActuals(actuals);
                std::for_each(expecteds.begin(), expecteds.end(), [&checkActuals](const T & expected) {
                    checkActuals.erase(
                        std::remove_if(checkActuals.begin(), checkActuals.end(), [& expected](const T & checkActuals) {
                            return expected == checkActuals;
                        })
                    );
                });
                unorderedEquals = checkActuals.empty();
            }
            if (!unorderedEquals) {
                m_testFailed = true;
                std::cout << "          expect unordered " << expecteds << std::endl  << " but is equal to unordered " << actuals << std::endl;
            }
            return unorderedEquals;
        }

        int m_called;

        static int TEST_NUMBER;
        bool m_testFailed;
};

#endif // TEST_TEST_H_