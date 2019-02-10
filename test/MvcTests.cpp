#include "MvcTests.h"

#include "../mvc/Notifier.h"
#include "../mvc/Listener.h"
#include "Test.h"

class TestNotifier: public Notifier<TestNotifier> {
    public:
        TestNotifier() : m_value(0) {}
        int getValue() const {
            return m_value;
        }
        void setValue(int value) {
            m_value = value;
            notify(*this);
        }
    
    private:
        int m_value;
};

void MvcTests::testListenerCall() {
    TestNotifier testNotifier;
    Test test;
    Listener<TestNotifier> testNotifierListener(
        [&](const TestNotifier udpatedTestNotifier) {
            test.expectCall();
            test.expectTrue(udpatedTestNotifier.getValue() == 2);
    });
    testNotifier.addListener(testNotifierListener);
    testNotifier.setValue(2);
    test.runExpectation();
}

void MvcTests::runAll() {
    testListenerCall();
}