#include "Day18.h"
#include <iostream>

extern int externint;

const int variable = 10;

// unnamed namesapce, resloves issues with naming, 
//in this case we can use global variable x in other files too
namespace 
{
    int x = 0;
}

void Day18()
{
    std::cout << externint << "\n";

    Test::NamespaceExample();

    // This local variable hides global variable with the same name 
    int variable = 20;
    std::cout << "Variable is: " << variable << "\n";
    std::cout << "Global variable with the same name is: " << ::variable << "\n";
}

void Test::NamespaceExample()
{
    std::cout << "Test" << std::endl;

    // Namespace alias
    namespace T = Test;
    T::NamespaceAlias();
}

void Test::NamespaceAlias()
{
    std::cout << "Namespace alias\n" << std::endl;
}
