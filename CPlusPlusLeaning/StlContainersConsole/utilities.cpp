#include <random>
#include <chrono>
#include <limits>

#include "utilities.h"

std::string utilities::working_status_to_string(working_status status)
{
    switch (status)
    {
    case off_duty:
        return "off duty";
    case idle:
        return "idle";
    case working:
        return "working";
    case sleeping:
        return "sleeping";
    default:
        return "unknown";
    }
}

int utilities::get_random_value(int min, int max)
{
    const auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    const std::uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}

int utilities::get_random_value()
{
    return get_random_value(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
}
