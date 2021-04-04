#pragma once
#include "Cat.h"

enum class Errors
{
    SUCCESS,
    ERROR,
};

void Day9();

void ReferenceExample();
void ReferenceAdressess();
void CatTests();
void Switch(int x, int y);
void SwitchByPointers(int* x, int* y);
void SwitchByReference(int& x, int& y);
void PassingByValue();
void PassingByPointer();
void PassingByReference();
Errors Factorial(int number, int* p_power_two, int* p_power_by_three);
void FactorialExample();
void ExampleOfObjectCallings();
void CreatingCatAtHeapExample();

void Exercise18();
