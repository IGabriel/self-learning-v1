#pragma once

#include "definition.h"
#include "human.h"

class labor : public creature::human
{
private:
    working_status status_;

protected:

public:
    void go_to_work();
};

class master : public labor
{
public:
    
};
