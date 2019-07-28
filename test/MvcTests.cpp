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

TEST(testAddListener,
    TestNotifier testNotifier;
    Listener listener([]() {});
    testNotifier.addListener(&listener);
    expectTrue(testNotifier.contains(&listener));
)

TEST(testDifferentsIdentifiers,
    TestNotifier testNotifier;
    Listener listener1([]() {});
    Listener listener2([]() {});
    testNotifier.addListener(&listener1);
    testNotifier.addListener(&listener2);
    expectTrue(testNotifier.contains(&listener1));
    expectTrue(testNotifier.contains(&listener2));
)

TEST(testRemoveListener,
    TestNotifier testNotifier;
    Listener listener([]() {});
    testNotifier.addListener(&listener);
    expectTrue(testNotifier.contains(&listener));
    testNotifier.removeListener(&listener);
    expectFalse(testNotifier.contains(&listener));
)

TEST(testListenerCall,
    TestNotifier testNotifier;
    expectCall();
    Listener listener([&]() { raiseCall(); });
    testNotifier.addListener(&listener);
    testNotifier.setValue(2);
    runExpectation();
)

void MvcTests::runAll() {
    testAddListener();
    testDifferentsIdentifiers();
    testRemoveListener();
    testListenerCall();
}