#include "point.h"
#include <iostream>
#include <sstream>
#include <thread>

std::string point::to_string() const
{
    std::stringstream stream;
    stream << "x: " << x_ << "; y: " << y_ << "; z: " << z_;
    return stream.str();
}

void point::move_carefully(const point& p)
{
    auto action = [this, &p]
    {
        x_ = p.x_;
        y_ = p.y_;
        z_ = p.z_;
        std::cout << "Moved to position: " << to_string() << std::endl;
    };
    move(action);
}

void point::move_on_x(const int x)
{
    const point p(x, 0, 0);
    auto action = [this, &p]
    {
        x_ = p.x_;
        std::cout << "Moved on x axis, new position: " << to_string() << std::endl;
    };
    move(action);
}


void point::move(const std::function<void()> action)
{
    const unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    const std::uniform_int_distribution<int> distribution(5, 10);
    int total_time = distribution(generator);

    std::cout << "Current position: " << to_string() << std::endl;
    std::cout << "Need: " << total_time << " seconds." << std::endl;
    //std::cout << "Moving to position: " << p.to_string() << ". Need " << total_time << " seconds." << std::endl;

    while (total_time > 0)
    {
        total_time--;
        std::cout << "Moving, please wait..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    action();
}

