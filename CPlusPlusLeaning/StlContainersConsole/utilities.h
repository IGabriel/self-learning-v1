#pragma once

#include <string>
#include "definition.h"

class utilities
{
public:
    static std::string working_status_to_string(working_status status);
    static int get_random_value(int min, int max);
    static int get_random_value();
};
