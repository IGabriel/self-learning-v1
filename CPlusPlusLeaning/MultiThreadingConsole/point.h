#pragma once
#include <string>
#include <random>
#include <functional>
#include <chrono>

class point
{
protected:
    int x_;
    int y_;
    int z_;

public:
    point(int x, int y, int z) : x_(x), y_(y), z_(z) {}
    point() : point(0, 0, 0) {}
    virtual ~point();

    std::string to_string() const;

    void move_carefully(const point& p);
    void move_on_x(const int x);

    void move(const std::function<void()> action);

    bool operator==(const point& p) const;
    bool operator<(const point& p) const;
};

using namespace std::chrono;
class point4d : public point
{
private:
    system_clock time_;
public:
    point4d(int x, int y, int z, const system_clock& time) : point(x, y, z), time_(time) {}
    point4d();
    virtual ~point4d();
};