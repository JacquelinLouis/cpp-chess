#include "MvcTests.h"

#include "../mvc/Notifier.h"
#include "Test.h"

class TestNotifier: public Notifier {
    public:
        TestNotifier() : m_value(0) {}
        int getValue() const {
            return m_value;
        }
        void setValue(int value) {
            m_value = value;
            notify();
        }

        bool contains(Listener * listener) {
            return m_listeners.find(listener) != m_listeners.end();
        }

    private:
        int m_value;
};

void MvcTests::testAddListener() {
    TestNotifier testNotifier;
    Test test;
    Listener listener([]() {});
    testNotifier.addListener(&listener);
    Test::expectTrue(testNotifier.contains(&listener));
}

void MvcTests::testDifferentsIdentifiers() {
    TestNotifier testNotifier;
    Test test;
    Listener listener1([]() {});
    Listener listener2([]() {});
    testNotifier.addListener(&listener1);
    testNotifier.addListener(&listener2);
    Test::expectTrue(testNotifier.contains(&listener1));
    Test::expectTrue(testNotifier.contains(&listener2));
}

void MvcTests::testRemoveListener() {
    TestNotifier testNotifier;
    Test test;
    Listener listener([]() {});
    testNotifier.addListener(&listener);
    Test::expectTrue(testNotifier.contains(&listener));
    testNotifier.removeListener(&listener);
    Test::expectFalse(testNotifier.contains(&listener));
}

void MvcTests::testListenerCall() {
    TestNotifier testNotifier;
    Test test;
    test.expectCall();
    Listener listener([&]() { test.raiseCall(); });
    testNotifier.addListener(&listener);
    testNotifier.setValue(2);
    test.runExpectation();
}

void MvcTests::runAll() {
    testAddListener();
    testDifferentsIdentifiers();
    testRemoveListener();
    testListenerCall();
}