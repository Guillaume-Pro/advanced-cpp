#include <iostream>
#include <coroutine>

//
// https://en.cppreference.com/w/cpp/language/coroutines

// Une simple coroutine qui attend avant de continuer
struct SimpleCoroutine {
    struct promise_type {
        SimpleCoroutine get_return_object() {
            return SimpleCoroutine(std::coroutine_handle<promise_type>::from_promise(*this));
        }
        std::suspend_always initial_suspend() { return {}; }
        std::suspend_always final_suspend() noexcept { return {}; }
        void return_void() {}
        void unhandled_exception() {}
    };

    std::coroutine_handle<> handle;
    SimpleCoroutine(std::coroutine_handle<> h) : handle(h) {}
    void resume() {
        handle.resume();
    }
};

SimpleCoroutine Attendre() {
    co_await std::suspend_always{}; // Suspend la coroutine ici
    std::cout << "Coroutine reprise!" << std::endl;
}

int main() {
    auto coro = Attendre();
    std::cout << "Coroutine commencée, mais suspendue..." << std::endl;
    coro.resume(); // Reprend la coroutine
    return 0;
}
