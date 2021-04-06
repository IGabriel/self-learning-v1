#include <iostream>

#include "background_thread.h"
#include "thread_guard.h"

background_thread::background_thread(const std::function<void()>& action, const bool is_joinable)
    : action_completed_(false), is_joinable_(is_joinable), action_(action), on_started_(nullptr), on_completed_(nullptr) {}

void background_thread::go()
{
    std::thread t;
    thread_guard guard(t, is_joinable_);

    std::cout << "starting background thread, is joinable? " << is_joinable_ << " ." << std::endl;

    if (on_started_ != nullptr)
    {
        on_started_();
    }

    auto actual_action = [&]
    {
        action_();
        action_completed_ = true;
    };

    t = std::thread{ actual_action };

    std::cout << "background thread is running..." << std::endl;
    std::unique_lock<std::mutex> mutex_lock(mutex_);
    condition_variable_.wait(mutex_lock, [this] {return action_completed_; });

    std::cout << "background thread is completed." << std::endl;
    if (on_completed_ != nullptr)
    {
        on_completed_();
    }
}
