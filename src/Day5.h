#pragma once

void Day5();

float Temperature(int fahrenheit);
void ReturnExample();
int DoubleAmount(int input);

// In prototype we can define default values for each parameter, the only rule is that if any parameter doesn't have default value 
// every parameter before this parameter is not allowed to have default parameter as well
void CapacityOfCuboid(int lenght, int width = 25, int height = 1);

// Inline function 
// If we use word inline before our function compilator will use body of this function and insert it everywhere in our code, which means program will be
// a little bit quicker, because it won't jump from function to function, but on the other hand program will be larger!
inline int TrippleAmount(int input) { return input * 3; }
void InlineFunctionTest();

// Recursion example
int FibonacciNumber(int numberInSequence);
void FibonacciTest();

//Exercises
unsigned long int Circumference(unsigned short int lenght, unsigned short int width);
float Exercise9(unsigned short firstNumber, unsigned short secondNumber);
void Exercise10();
int Exercise11();
int PowerNumber(int baseNumber, int powerNumber);