#pragma once

#include "master.h"

class slave : public labor
{
public:
    slave(const std::string& name, int age) : labor(name, age), pMaster_(nullptr) {}
    slave(const std::string& name) : slave(name, 0) {}

    void set_master(master* pM) { pMaster_ = pM; }
    master* get_master() const { return pMaster_; }

private:
    master* pMaster_;
};
