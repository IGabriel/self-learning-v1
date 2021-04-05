#include "human.h"
#include <iostream>
#include <atomic>

static std::atomic_long next_id = 0;

long GetNextId()
{
    return next_id.fetch_add(1);
}

creature::human::human(long id, const std::string& name, int age)
    : id_(id), name_(name), age_(age)
{
    show_human_info(*this);
}

creature::human::human(const std::string& name, int age)
    : human(GetNextId(), name, age) {}

creature::human::human(const std::string& name)
    : human(name, 0) {}

creature::human::human()
    : human("", 0) {}

creature::human::human(const human& obj)
{
    std::cout << "Copying." << std::endl;
    deep_copy_from(obj);
    std::cout << "Copied constructor, id: " << id_ << std::endl;
}

creature::human creature::human::operator=(const human& obj)
{
    std::cout << "assigning." << std::endl;
    deep_copy_from(obj);
    std::cout << "Operator assignment, id: " << id_ << std::endl;
    return *this;
}

bool creature::human::operator==(const human& obj) const
{
    return name_ == obj.GetName();
}

creature::human::~human()
{
    std::cout << "deleting human, id: " << id_ << "; name: " << name_ << std::endl;
}

void creature::human::deep_copy_from(const human& source)
{
    name_ = source.name_;
    id_ = GetNextId();
    age_ = source.GetAge() + 1;
    std::cout << "deep copied, source id: " << source.GetId() << ", current id: " << id_ << std::endl;
}

long creature::human::GetId() const { return id_; }

std::string creature::human::GetName() const { return name_; }

int creature::human::GetAge() const { return age_; }

void creature::human::SetAge(int age)
{
    age_ = age;
}

void creature::human::show_human_info(const human& h)
{
    std::cout << "id: " << h.GetId() << "; Name: " << h.GetName() << "; Age: " << h.GetAge() << "." << std::endl;
}
