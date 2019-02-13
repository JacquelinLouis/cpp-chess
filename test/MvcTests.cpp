#include "MvcTests.h"

#include "../mvc/Notifier.h"
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

        bool contains(int id) {
            return m_listeners.find(id) != m_listeners.end();
        }

    private:
        int m_value;
};

void MvcTests::testAddListener() {
    TestNotifier testNotifier;
    Test test;
    std::function<void(TestNotifier)> listener =
        [](const TestNotifier updatedTestNotifier) {};
    int listenerId = testNotifier.addListener(listener);
    test.expectTrue(testNotifier.contains(listenerId));
}

void MvcTests::testDifferentsIdentifiers() {
    TestNotifier testNotifier;
    Test test;
    int listenerId1 = testNotifier.addListener(
        [](const TestNotifier updatedTestNotifier) {});
    int listenerId2 = testNotifier.addListener(
        [](const TestNotifier updatedTestNotifier) {});
    test.expectTrue(listenerId1 != listenerId2);
}

void MvcTests::testRemoveListener() {
    TestNotifier testNotifier;
    Test test;
    int listenerId = testNotifier.addListener(
        [](const TestNotifier updatedTestNotifier) {
    
        });
    test.expectTrue(testNotifier.contains(listenerId));
    testNotifier.removeListener(listenerId);
    test.expectFalse(testNotifier.contains(listenerId));
}

void MvcTests::testListenerCall() {
    TestNotifier testNotifier;
    Test test;
    test.expectCall();
    testNotifier.addListener(
        [&](const TestNotifier udpatedTestNotifier) {
            test.call();
            test.expectTrue(udpatedTestNotifier.getValue() == 2);
    });
    testNotifier.setValue(2);
    test.runExpectation();
}

void MvcTests::runAll() {
    testAddListener();
    testDifferentsIdentifiers();
    testRemoveListener();
    testListenerCall();
}