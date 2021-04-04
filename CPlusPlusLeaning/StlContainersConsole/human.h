#pragma once
#include <string>

namespace creature
{
    class human
    {
    private:
        long id_;
        std::string name_;
        int age_;
        void deep_copy_from(const human& source);

    public:
        human();
        human(const std::string& name);
        human(const std::string& name, int age);
        human(long id, const std::string& name, int age);
        human(const human& obj);
        virtual ~human();
        human operator=(const human& obj);

        long GetId() const;
        std::string GetName() const;

        int GetAge() const;
        void SetAge(int age);

        static void show_human_info(const human& h);
    };
}