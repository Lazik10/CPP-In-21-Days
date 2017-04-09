#include <iostream>
#include "Day1.h"
#include "Day2.h"
#include "Day3.h"

using namespace std;

int main()
{   
    // First compile test
    //cout << "Hello CMake!" << endl;

    cout << "Learning C++ In 21 Days\n\n" << endl;
    Day3();

    // Use this method twice because sometimes when we input something 
    // in the last called function it takes as if we input it here
    getchar();
    getchar();
    return 0;
}