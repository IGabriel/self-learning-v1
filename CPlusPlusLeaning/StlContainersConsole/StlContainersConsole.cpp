// StlContainersConsole.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "human.h"
#include "labor.h"

void BaseConstructorTest()
{
    std::cout << "Test base class behavior..." << std::endl;

    const creature::human felix("felix");
    const creature::human guan_qing("guan qing");

    std::cout << "Making a empty human..." << std::endl;
    const creature::human empyt;

    std::cout << "Show exist humans..." << std::endl;
    creature::human::show_human_info(felix);
    creature::human::show_human_info(guan_qing);
    creature::human::show_human_info(empyt);
}

void BaseVectorTest()
{
    std::cout << "Test vector with instance..." << std::endl;
    const creature::human h1("h1");
    
    std::cout << "adding to vector, expected deep copy here..." << std::endl;
    std::vector<creature::human> v;
    v.push_back(h1);

    std::cout << "get object from vector, expected deep copy here..." << std::endl;
    const creature::human getIt = v.at(0);

    std::cout << "show what I got:" << std::endl;
    creature::human::show_human_info(getIt);
}

void BaseVectorPtrTest()
{
    std::cout << "Test vector with pointer..." << std::endl;
    creature::human h1("h1");

    std::cout << "adding pointer to vector, expected no copy here..." << std::endl;
    std::vector<creature::human*> v;
    v.push_back(&h1);

    std::cout << "getting pointer to vector, expected no copy here..." << std::endl;
    const creature::human* getIt = v.at(0);

    std::cout << "show what I got:" << std::endl;
    creature::human::show_human_info(*getIt);
}

std::vector< std::shared_ptr<creature::human>> BaseVectorSharedPtrTest_MakeVector()
{
    const std::shared_ptr<creature::human> felix = std::make_shared<creature::human>("felix");

    std::cout << "adding shared_ptr to vector, expected no copy here..." << std::endl;
    std::vector< std::shared_ptr<creature::human>> v;
    v.push_back(felix);

    return v;
}

void BaseVectorSharedPtrTest()
{
    std::cout << "return shared_ptr vector..." << std::endl;
    auto v = BaseVectorSharedPtrTest_MakeVector();
    std::cout << "getting shared_ptr to vector, expected no copy here..." << std::endl;
    const auto gotItem = v.at(0);
    std::cout << "show what I got:" << std::endl;
    creature::human::show_human_info(*gotItem);
}

void assignment_test()
{
    std::cout << "testing assignment operator." << std::endl;
    const creature::human h0("Felix");
    const creature::human h1 = h0;

    std::cout << "Initialize h1!" << std::endl;
    creature::human h2;

    std::cout << "assignment operator!" << std::endl;
    h2 = h1;

    std::cout << "testing assignment operator done!" << std::endl;
}

std::vector<creature::human> return_vector_by_local_variable()
{
    std::vector<creature::human> v;

    std::cout << "creating human instances..." << std::endl;
    const creature::human felix("felix");
    const creature::human chen("chen");

    std::cout << "push into vector..." << std::endl;
    v.push_back(felix);
    v.push_back(chen);

    std::cout << "return vector..." << std::endl;
    return v;
}

void return_vector_deep_copy_elements()
{
    std::cout << "testing vector as return value:" << std::endl;
    auto v = return_vector_by_local_variable();

    std::cout << "showing human info..." << std::endl;
    for(const creature::human& h : v)
    {
        creature::human::show_human_info(h);
    }

    std::cout << "all done!" << std::endl;
}

void fill_vectors(std::vector<creature::human>& v)
{
    std::cout << "creating human instances..." << std::endl;
    const creature::human felix("felix");
    const creature::human chen("chen");

    std::cout << "push into vector..." << std::endl;
    v.push_back(felix);
    v.push_back(chen);

    std::cout << "return vector..." << std::endl;
}

void pass_vector_by_argument()
{
    std::vector<creature::human> v;

    std::cout << "testing vector as argument:" << std::endl;
    fill_vectors(v);

    std::cout << "showing human info..." << std::endl;
    for (const creature::human& h : v)
    {
        creature::human::show_human_info(h);
    }
    std::cout << "all done!" << std::endl;
}

void fill_vectors_by_pointer(std::vector<creature::human>* pV)
{
    std::cout << "creating human instances..." << std::endl;
    const creature::human felix("felix");
    const creature::human chen("chen");

    std::cout << "push into vector..." << std::endl;
    pV->push_back(felix);
    pV->push_back(chen);

    std::cout << "return vector..." << std::endl;
}

void pass_vector_by_pointer()
{
    std::vector<creature::human> v;

    std::cout << "testing vector as pointer:" << std::endl;
    fill_vectors_by_pointer(&v);

    std::cout << "showing human info..." << std::endl;
    for (const creature::human& h : v)
    {
        creature::human::show_human_info(h);
    }
    std::cout << "all done!" << std::endl;
}

void compare_human()
{
    creature::human felix1("felix");
    creature::human felix2("felix");

    if (felix1 == felix2)
    {
        std::cout << "equaled, compare by name." << std::endl;
    }
    else
    {
        std::cout << "What is going on?!" << std::endl;
    }
}

void friend_keyword_test()
{
    master m("felix");
    m.go_to_work();
}

int main()
{
    //BaseConstructorTest();
    //BaseVectorTest();
    //BaseVectorPtrTest();
    
    //BaseVectorSharedPtrTest();
    //assignment_test();
    
    //return_vector_deep_copy_elements();
    //pass_vector_by_argument();
    //pass_vector_by_pointer();

    //compare_human();

    friend_keyword_test();
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
