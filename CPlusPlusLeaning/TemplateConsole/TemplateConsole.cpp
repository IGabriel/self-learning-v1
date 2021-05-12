// TemplateConsole.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "CommonLibrary\VectorParser.h"

#include <iostream>
#include <vector>
#include <list>
#include <initializer_list>

int main()
{
    //std::cout << "Hello World!\n";

    //int rc = double_current_value<int>(3);
    //printf("double: %d.\r\n", rc);

    //double power_result = power(3.0, 3);
    //printf("power: %lf.\r\n", power_result);
    //

    //std::vector<int> v{ 3, 1, -14, 1, 5, 9 };

    //std::vector<int>::iterator result = std::max_element(v.begin(), v.end());
    //std::cout << "max element at: " << std::distance(v.begin(), result) << '\n';

    
    //std::vector<int> elements{ 1, 2, 3, 4, 5 };

    //auto max_value = std::max(elements.begin(), elements.end());
    //double max_value = std::max({ 10.1, 10.2, 9.0, 50.3, 8.3, 20.1 });


    const std::vector<double> elements1{ 10.1, 10.2, 9.0, 8.3, 20.1 };
    VectorParser<double> parser(elements1);

    for(const double item : parser.get_element())
    {
        printf("current value: %lf.\n", item);
    }

    printf("Next test:\r\n");

    const std::vector<double> elements2{ 100.1, 80.2, 99.0 };
    parser.set_element(elements2);

    for (const double item : parser.get_element())
    {
        printf("current value: %lf.\n", item);
    }

    //printf("max: %d.", max_value);

    //printf("max: %lf", parser.get_max());
    //printf("min: %lf", parser.get_min());
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
