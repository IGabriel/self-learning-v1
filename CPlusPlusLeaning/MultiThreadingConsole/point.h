#pragma once
#include <string>
#include <random>
#include <functional>

class point
{
private:
    int x_;
    int y_;
    int z_;

public:
    point(int x, int y, int z) : x_(x), y_(y), z_(z) {}
    point() : point(0, 0, 0) {}
    std::string to_string() const;

    void move_carefully(const point& p);
    void move_on_x(const int x);

    void move(const std::function<void()> action);
};
