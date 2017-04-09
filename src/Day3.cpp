#include <iostream>
#include <ctime>
#include "Day3.h"

// Typedef - we can rename current data types to our own aliases
typedef unsigned int uint32;
typedef int          int32;

// Constant Definition - we should use the second one
#define         MY_FIRST_CONSTANT_DEFINITION            = 1;
const int32     MY_SECOND_CONSTANT_DEFINITION           = 1;

using namespace std;

// VARIABLES 

void Day3()
{
    TestSizeOfData();
    PrintASCIITable();
    WhatDayIsToday();

    /// Page 78 Exercises

    // 1. and 2.)
    unsigned short int myAge = 25;
    float myGardenSize = 200;
    double starsInGalaxy = 100000000000000000;
    unsigned short averageDawnfall = 500;

    // 3. and 4.)
    const float PI = 3.14159;
    float myPi = PI;

}

void TestSizeOfData()
{
    // Data types                                                           // VALUES TABLE

    // Boolean
    cout << "Size of Bool is " << sizeof(bool) << " bytes" << endl;         // True / False
    // Character
    cout << "Size of Char is " << sizeof(char) << " bytes" << endl;         // 256 character values
    // Integer
    cout << "Size of Int is: " << sizeof(int) << " bytes" << endl;          // -2 147 483 648 to 2 147 483 647          - unsigned 0 to 4 294 967 295
    // Short Integer
    cout << "Size of Short is: " << sizeof(short) << " bytes" << endl;      // -32 768 to 32767                         - unsigned 0 to 65535 
    // Long Integer
    cout << "Size of Long is: " << sizeof(long) << " bytes" << endl;        // -2 147 483 648 to 2 147 483 647          - unsigned 0 to 4 294 967 295
    // Float
    cout << "Size of Float is " << sizeof(float) << " bytes" << endl;       // 1.2e-38 to 3.4e38
    // Double
    cout << "Size of Double is " << sizeof(double) << " bytes" << endl;     // 2.2e-308 to 1.8e308
}

// Key Words - We shouldn't use these as our variable name
/*
    asm, auto, bool, break, case, catch, char, class, const, const_cast, continue, default, delete, do, double, dynamic_cast, else
    enum, explicit, export, extern, false, float, for, friend, goto, if, inline, int, long, mutable, namespace, new, operator, private
    protected, public, register, reinterpret_cast, return, short, signed, sizeof, static, static_cast, struct, switch, template, this
    throw, true, try, typedef, typeid, typename, union, unsigned, using, virtual, void, volatile, wchar_t, while,
    
    and, and_eq, bitand, bitor, compl, not, not_eq, or, or_eq, xor, xor_eq
*/

void PrintASCIITable()
{
    cout << "\n      --- ASCII TABLE ---" << endl;

    for (int32 i = 0; i < 256/4; i++)
    {
        cout << i << "  " << (char)i << "\t" << i+64 << "  " << char(i+64) << "\t" << i+128 << "  " << char(i+128) << "\t" << i+192 << "  "<<char(i+192) << endl;
    }
    cout << endl;

    for (char i = 0; i < 256/4; i++)
    {
        cout << int(i) << "  " << i << "\t" << int(i) + 64 << "  " << char(i + 64) << "\t" << int(i) + 128 << "  " << char(i + 128)  << "\t" << int(i) + 192 << "  " << char(i + 192) << endl;
    }
    cout << endl;
}

// Special Characters
char Ring = '\a';
char Backspace = '\b';
char nextFile = '\f';
char newLine = '\n';
char Tab = '\t';
char verticalTab = '\v';
char aostrophe = '\'';
char quotes = '\"';
char questionmark = '\?';
char backslash = '\\';
char octal = '\000';
char hexadecimal = '\x000';

// Enum - declares new type and every enumerated type has it's own value starting from 0
//        unless we inicialize any of them, then the next enumerated type will have it's value bigger by 1 than previous one
//        enumerated type in enum is taken as unsigned integer
enum Color // Name of the new type
{
    RED,                // 0
    BLUE = 100,         // 100
    GREEN,              // 101
    BLACK,              // 102
    YELLOW = 50,        // 50
    ORANGE = 98+2,      // 100 - it is possible to make two enumerated type with the same value
    PURPLE,             // 101
};

int RandomNumber(int max)
{
    // Innitialize random seed, we also need to include <ctime> library
    srand(time(NULL));

    /* 
    Examples
    rand() % 100;         // in the range 0 to 99
    rand() % 100 + 1;     // in the range 1 to 100
    rand() % 30 + 1985;   // in the range 1985-2014
    */
    int randomNumber = rand() % max;

    return randomNumber;
}

void WhatDayIsToday()
{
    enum Days { MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY, ALL_WEEKEND };

    int today = RandomNumber(ALL_WEEKEND);
    cout << today << endl;

    if (today == SATURDAY || today == SUNDAY)
        cout << "Weekend!" << endl;
    else
        cout << "Get up, you have to go to work!" << endl;
}