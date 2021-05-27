// ThreadsConsole.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <mutex>

volatile int counter(0);
//std::mutex mtx;

 // constructor -----------------------------

void foo(std::string& name)
{
    printf("Yield! my name is: %s.\n", name.c_str());

    std::this_thread::yield();

    name = "GuanQing";
}

void base_thread()
{
    std::string name("felix");
    std::thread t(foo, std::ref(name));
    t.join();

    printf("What is my name now? %s.\n", name.c_str());
}

void base_thread_lambda_reference()
{
    std::string name("felix");

    std::thread t([&name]
        {
            printf("lambda, reference, my name is: %s.\n", name.c_str());
            name = "GuanQing";
        });
    t.join();
    printf("What is my name now? %s.\n", name.c_str());
}

void base_thread_lambda_value()
{
    std::string name("felix");

    std::thread t([=] () mutable 
        {
            printf("lambda, value, my name is: %s.\n", name.c_str());
            name = "GuanQing";
        });
    t.join();
    printf("What is my name now? %s.\n", name.c_str());
}

void joinable_test()
{
    std::thread t1;
    printf("t1 should not be join, right? %d.\n", t1.joinable());

    std::string name("felix-join");
    std::thread t(foo, std::ref(name));

    printf("sleeping 3 seconds. wait for thead: %d.\n", t.get_id());
    std::this_thread::sleep_for(std::chrono::milliseconds(3));

    printf("my new name: %s.\n", name.c_str());

    std::thread new_thread(std::move(t));

    printf("t [%d] should not be join, right? %d.\n", t.get_id(), t.joinable());
    printf("new_thread [%d] should not be join, right? %d.\n", new_thread.get_id(), new_thread.joinable());

    if (t.joinable())
    {
        t.join();
    }
    if (new_thread.joinable())
    {
        new_thread.join();
    }

    printf("Done!\n");
}

// Mutex ---------------------------------------------------------

void attempt_10k_increase(std::mutex& m)
{
    for (int i = 0; i < 100; ++i)
    {
        if (m.try_lock())
        {
            ++counter;
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
            printf("[%d] done.\n", std::this_thread::get_id());
            m.unlock();
        }
        else
        {
            printf("[%d] failed!!!!!\n", std::this_thread::get_id());
        }
    }
}

void mutex_test()
{
    std::mutex mtx;

    std::thread threads[10];
    for(int i = 0; i < 10; ++i)
    {
        threads[i] = std::thread(attempt_10k_increase, std::ref(mtx));
    }
    for (std::thread& t : threads)
    {
        t.join();
    }

    printf("all done.");
}


int main()
{
    //base_thread();
    //base_thread_lambda_reference();
    //base_thread_lambda_value();
    //joinable_test();
    mutex_test();
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
