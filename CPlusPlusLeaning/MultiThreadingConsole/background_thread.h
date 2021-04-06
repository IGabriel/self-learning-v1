#pragma once
#include <functional>
#include <condition_variable>
#include <mutex>

class background_thread
{
private:
    bool action_completed_;
    std::mutex mutex_;
    std::condition_variable condition_variable_;

    bool is_joinable_;
    std::function<void()> action_;
    std::function<void()> on_started_;
    std::function<void()> on_completed_;
public:
    explicit background_thread(const std::function<void()>& action, const bool is_joinable);
    explicit background_thread(const std::function<void()>& action) : background_thread(action, true) {}
    void set_on_started_handler(const std::function<void()>& handler) { on_started_ = handler; }
    void set_on_completed_handler(const std::function<void()>& handler) { on_completed_ = handler; }
    void go();
};
