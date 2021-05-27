#include "labor.h"
#include "utilities.h"

#include <iostream>

void labor::update_status()
{
    status_ = static_cast<working_status>(utilities::get_random_value(working_status_min_value, working_status_max_value));
    std::cout << "Current status: " << utilities::working_status_to_string(status_) << std::endl;
}

void labor::go_to_work()
{
    update_status();

    if (status_ == off_duty || status_ == sleeping)
    {
        std::cout << GetName() << ": " << "NO! I would not go to work." << std::endl;
    }
    else
    {
        std::cout << GetName() << ": " << "Yes, sir!" << std::endl;
    }
}
