#pragma once

#include "definition.h"
#include "human.h"
#include <vector>

class labor : public creature::human
{
public:
    labor(const std::string& name, int age) : human(name, age) {}
    virtual void go_to_work();

protected:
    void update_status();

private:
    working_status status_;
};

class slave;

class master : public labor
{
public:
    master(const std::string& name, int age) : labor(name, age) {}
    master(const std::string& name) : master(name, 0) {}

private:
    std::vector<slave*> slave_ptrs;
    friend void add_slave(slave* p_slave);
};

class slave : public labor
{
public:
    slave(const std::string& name, int age) : labor(name, age), pMaster_(nullptr) {}
    slave(const std::string& name) : slave(name, 0) {}

private:
    master* pMaster_;
};
