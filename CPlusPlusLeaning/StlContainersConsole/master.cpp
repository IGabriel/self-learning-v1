#include <iostream>
#include "master.h"
#include "utilities.h"

void labor::go_to_work()
{
    status_ = static_cast<working_status>(utilities::get_random_value(working_status_min_value, working_status_max_value));

    std::cout << "Current status: " << utilities::working_status_to_string(status_) << std::endl;

    if (status_ == off_duty || status_ == sleeping)
    {
        std::cout << GetName() << ": " << "NO! I would not go to work." << std::endl;
    }
    else
    {
        std::cout << GetName() << ": " << "Yes, sir!" << std::endl;
    }
}
