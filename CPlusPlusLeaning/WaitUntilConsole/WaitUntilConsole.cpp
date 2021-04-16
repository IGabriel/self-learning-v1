// WaitUntilConsole.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex m;
std::condition_variable cv;
std::string data;
bool ready = false;
bool processed = false;

void worker_thread()
{
    // Wait until main() sends data
    std::unique_lock<std::mutex> lk(m);
    cv.wait(lk, [] {return ready; });

    // after the wait, we own the lock.
    std::cout << "Worker thread is processing data\n";
    data += " after processing";

    // Send data back to main()
    processed = true;
    std::cout << "Worker thread signals data processing completed\n";

    // Manual unlocking is done before notifying, to avoid waking up
    // the waiting thread only to block again (see notify_one for details)
    lk.unlock();
    cv.notify_one();
}

#include <list>
#include <vector>
#include <set>
#include <array>
#include <map>
#include <memory>

void Test()
{
    std::list<int> l;
    std::vector<int> v;

    std::unique_ptr<int> up = std::make_unique<int>(10);
    const std::shared_ptr<int> mp = std::make_shared<int>(20);

    std::weak_ptr<int> wp(mp);
    std::shared_ptr<int> ssp = wp.lock();

    int values[] = { 1, 2 };

    //std::array<int, 4> values { 1, 2, 2, 3 };
    //std::multiset<int> s(values.begin(), values.end());
    //const std::pair<std::multiset<int>::iterator, std::multiset<int>::iterator> range = s.equal_range(2);
    //for(std::multiset<int>::iterator it = range.first; it != range.second; ++it)
    //{
    //    std::cout << *it << std::endl;
    //}
    //
    std::multimap<int, std::string> m;
    m.insert(std::make_pair(1, "a"));
    m.insert(std::make_pair(2, "b"));
    m.insert(std::make_pair(3, "b1"));
    m.insert(std::make_pair(3, "b2"));
    m.insert(std::make_pair(3, "b3"));
    m.insert(std::make_pair(4, "d"));
    m.insert(std::make_pair(5, "e"));

    const std::pair<std::multimap<int, std::string>::iterator, std::multimap<int, std::string>::iterator> range = m.equal_range(9);

    for(std::multimap<int, std::string>::iterator it = range.first; it != range.second; ++it)
    {
        std::cout << "key: " << it->first << "; value: " << it->second << std::endl;
    }

}

int main()
{
    Test();
    /*
    std::thread worker(worker_thread);

    data = "Example data";
    // send data to the worker thread
    {
        std::lock_guard<std::mutex> lk(m);
        ready = true;
        std::cout << "main() signals data ready for processing\n";
    }
    cv.notify_one();

    // wait for the worker
    {
        std::unique_lock<std::mutex> lk(m);
        cv.wait(lk, [] {return processed; });
    }
    std::cout << "Back in main(), data = " << data << '\n';

    worker.join();
    */
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
