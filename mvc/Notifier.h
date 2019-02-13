#ifndef MVC_NOTIFIER_H_
#define MVC_NOTIFIER_H_

#include<functional>
#include <map>

template <class UpdatedType>
class Notifier {
    public:
        /**
         * @brief Store the given listener and return a unique identifier
         * 
         * @param listener listener to store and notify
         * @return int the unique identifier returned
         */
        int addListener(std::function<void(UpdatedType)> listener) {
            int id = k_identifier;
            m_listeners.emplace(id, listener);
            k_identifier += 1;
            return id;
        }
        void removeListener(int id) {
            m_listeners.erase(id);
        }
        void notify(const UpdatedType updatedObject) {
            for (const auto & listener : m_listeners) {
                listener.second(updatedObject);
            }
        }
    protected:
        std::map<int, std::function<void(UpdatedType)>> m_listeners;
        static int k_identifier;
};

template <class UpdatedType>
int Notifier<UpdatedType>::k_identifier = 0;

#endif // MVC_NOTIFIER_H_