#include <iostream>

// Week 1
#include "Day1.h"
#include "Day2.h"
#include "Day3.h"
#include "Day4.h"
#include "Day5.h"
#include "Day6.h"
#include "Day7.h"
// Week 2
#include "Day8.h"
#include "Day9.h"
#include "Day10.h"
#include "Day11.h"
#include "Day12.h"
#include "Day13.h"
#include "Day14.h"
#include "Review.h"
// Week 3
#include "Day15.h"
#include "Day16.h"
#include "Day17.h"
#include "Day18.h"

int externint = 5;

int main(int argc, char* argv[]) // argv can be declared as char* [argv][] or char** argv
{
    // argc - argument count in command line
    // argv - argument vector 

    // First compile test
    //cout << "Hello CMake!" << endl;

    std::cout << "Learning C++ In 21 Days\n\n" << std::endl;
    Day18();

    // Use this method twice because sometimes when we input something 
    // in the last called function it takes as if we input it here
    getchar();
    return 0;
}