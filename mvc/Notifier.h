#ifndef MVC_NOTIFIER_H_
#define MVC_NOTIFIER_H_

#include<functional>
#include <unordered_set>

#include "Listener.h"

class Notifier {
    public:
        /**
         * @brief Store the given listener and return a unique identifier
         * 
         * @param listener listener to store and notify
         * @return int the unique identifier returned
         */
        void addListener(Listener * listener) {
            m_listeners.emplace(listener);
        }

        void removeListener(Listener * listener) {
            m_listeners.erase(listener);
        }

        void notify() {
            for (const auto & listener : m_listeners) {
                listener->notify();
            }
        }

    protected:
        std::unordered_set<Listener *> m_listeners;
};

#endif // MVC_NOTIFIER_H_