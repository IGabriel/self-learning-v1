// MultiThreadingConsole.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>
#include <thread>
#include <atomic>
#include <mutex>
#include <condition_variable>

#include "point.h"
#include "thread_guard.h"
#include "utilites.h"


void greeting()
{
    std::cout << "Running background thread..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Background thread completed." << std::endl;
}

void SimpleThreadingTest()
{
    std::thread t{ greeting };

    std::cout << "Wait for one second." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    //std::cout << "Main threading..." << std::endl;
    if (t.joinable())
    {
        t.join();
    }
}

void ThreadGuardTest()
{
    std::cout << "Thread guard test." << std::endl;

    std::thread t;
    thread_guard guard(t);

    t = std::thread{ greeting };
    std::cout << "function exit." << std::endl;
}

void thread_proc_param(int x, int y, const std::string& name)
{
    std::cout << "Running background thread..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::cout << "x: " << x << "; y: " << y << "; name: " << name << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::cout << "Background thread completed." << std::endl;
}

void thread_with_parameters()
{
    std::cout << "Thread with parameters." << std::endl;

    std::thread t{ thread_proc_param, 10, 20, "felix" };
    if (t.joinable())
    {
        t.join();
    }
}

void thread_member_function_with_parameters()
{
    point source(1, 2, 3);
    point destination(10, 20, 30);
    
    std::cout << "Moving in background thread..." << std::endl;

    std::thread t(&point::move_carefully, std::ref(source), destination);

    std::cout << "done!" << std::endl;
}

bool started = false;
bool done = false;

void proc(std::condition_variable* condition, std::unique_lock<std::mutex>* locker)
{
    condition->wait(*locker, [] { return started; });

    std::cout << "Running in background thread, waiting for start flag..." << std::endl;

    std::cout << "Background thread need 5 seconds." << std::endl;
    wait(5);

    done = true;
}

void condition_variable_test()
{
    std::mutex m;
    std::condition_variable condition;

    std::unique_lock<std::mutex> locker(m);

    point p;
    std::thread t { proc, &condition, &locker };
    //t.detach();

    std::cout << "let's wait 5 seconds, then start background thread." << std::endl;
    wait(5);
    started = true;

    condition.wait(locker, [] { return done; });

    std::cout << "Looks good!" << std::endl;

    t.join();
}

int main()
{
    //SimpleThreadingTest();
    //ThreadGuardTest();
    //thread_with_parameters();
    //thread_member_function_with_parameters();
    condition_variable_test();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
