#include "master.h"
#include <iostream>

void labor::go_to_work()
{
    std::cout << "Current status: " << working_status_to_string(status_) << std::endl;
}
