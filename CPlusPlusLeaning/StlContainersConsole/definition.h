#pragma once

enum working_status
{
    off_duty = 0,
    idle = 1,
    working = 2,
    sleeping = 3
};

const int working_status_min_value = 0;
const int working_status_max_value = 3;