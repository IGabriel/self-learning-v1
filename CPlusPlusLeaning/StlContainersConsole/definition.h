#pragma once

#include <string>

enum working_status
{
    off_duty = 0,
    idle = 1,
    working = 2,
    sleeping = 3
};

static std::string working_status_to_string(working_status status)
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

int get_ra