#include <iostream>
#include "Day2.h"

using namespace std;

void Day2()
{
    cout << "Day 2:\n\n";

    /// 3 -Comment types - they should give information about WHY it is happening not WHAT is happening

    // Single line comment

    /*
        Multi-line comment
    */

    /// Documentation comment

    // Call ExampleFunction() with parametres, note that we don`t have to put all three parameters because our prototype
    ExampleFunction(10, 20);

    Exercise3();
    Exercise4();
    Exercise5();
}

// This is a declaration part of function called ExampleFunction, it`s prototype is in header file
// Basicaly here we decide what this function is going to do
void ExampleFunction(int x, int y, int z)
{
    cout << "X is: " << x << endl << "Y is: " << y << endl << "Z is :" << z << endl << endl;
}

/// Page 56 Exercises

// 1.) We should write a program which prints I love C++ on screen
void Exercise3()
{
    cout << "I love C++\n" << endl;
}

// 2.) We should write tha smallest possible program which can run itself
//    - It should be int main () {}

// 3.) and 4.) Fix error, compile and run
void Exercise4()
{
    cout << "Je zde chyba?\n" << endl;
}

// 5) Addition (+) and Subtraction (-)
void Exercise5()
{
    int x, y = 0;
    cout << "Input two numbers:\n";
    cin >> x;
    cin >> y;

    Addition(x, y);
    Subtraction(x, y);
}

int Addition(int x, int y)
{
    cout << "Addition of these two numbers is: " << x + y << endl;
    return x + y;
}

int Subtraction(int x, int y)
{
    cout << "Subtraction of these two numbers is: " << x - y << endl;
    return x - y;
}