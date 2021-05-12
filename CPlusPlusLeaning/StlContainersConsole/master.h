#pragma once

#include "definition.h"
#include "human.h"

class labor : public creature::human
{
private:
    working_status status_;

protected:

public:
    labor(const std::string& name, int age) : human(name, age) {}
    virtual void go_to_work();
};

class master : public labor
{
public:
    master(const std::string& name, int age) : labor(name, age) {}
    master(const std::string& name) : master(name, 0) {}
};
