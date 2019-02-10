#ifndef MVC_LISTENER_H_
#define MVC_LISTENER_H_

#include <functional>

template <class UpdatedType>
class Listener {
    public:
        Listener(std::function<void(const UpdatedType)> onChange_cb)
            : notificationCallback(onChange_cb)
        {}

        bool operator<(const Listener & otherListener) const {
            return this == &otherListener;
        }

        void notify(const UpdatedType updatedObject) const {
            notificationCallback(updatedObject);
        }

    private:
        std::function<void(const UpdatedType)> notificationCallback;
};

#endif // MVC_LISTENER_H_