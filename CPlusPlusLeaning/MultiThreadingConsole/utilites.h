#pragma once

#include <iostream>
#include <chrono>
#include <thread>

inline void wait(int seconds)
{
    std::cout << "waiting for " << seconds << " seconds." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

inline void wait_one_seconds()
{
    wait(1);
}
