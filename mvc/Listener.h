#ifndef MVC_LISTENER_H_
#define MVC_LISTENER_H_

#include <functional>

class Listener {
public:
    Listener(std::function<void()> callback): m_callback(callback) {}
    void notify() { m_callback(); }

private:
    std::function<void()> m_callback;
};

#endif // MVC_LISTENER_H_