#pragma once

#include <thread>

struct thread_guard
{
private:
    std::thread& t_;
    bool joined_;

public:
    explicit thread_guard(std::thread& t, bool joined): t_(t), joined_(joined) {}
    explicit thread_guard(std::thread& t) : thread_guard(t, true) {}
    ~thread_guard()
    {
        if (t_.joinable())
        {
            if (joined_)
            {
                t_.join();
            }
            else
            {
                t_.detach();
            }
        }
    }

    thread_guard(const thread_guard&) = delete;
    thread_guard& operator=(const thread_guard&) = delete;
};