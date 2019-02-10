#ifndef MVC_NOTIFIER_H_
#define MVC_NOTIFIER_H_

#include <set>

#include "Listener.h"

template <class UpdatedType>
class Notifier {
    public:
        void addListener(Listener<UpdatedType> listener) {
            m_listeners.insert(listener);
        }
        void removeListener(Listener<UpdatedType> listener) {
            m_listeners.erase(listener);
        }
        void notify(const UpdatedType updatedObject) {
            for (auto & listener : m_listeners) {
                listener.notify(updatedObject);
            }
        }
    private:
        std::set<Listener<UpdatedType>> m_listeners; 
};

#endif // MVC_NOTIFIER_H_