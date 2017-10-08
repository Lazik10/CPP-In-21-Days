#include <iostream>
#include "Day5.h"

using namespace std;

void Day5()
{
    Temperature(100); // Fahrenheit value
    ReturnExample();
    CapacityOfCuboid(10, 50); // This function has default width and height so we can use diferent amount of parameters between 1-3
    InlineFunctionTest();
    FibonacciTest();

    Exercise10();
    Exercise11();
}

// Function Prototype examples:
// long Field(int, int);
// long Field(int height, int lenght)
// we can have prototypes with names of parameters or even without

float Temperature(int fahrenheit)
{
    float temperatureCelsius;
    temperatureCelsius = ((fahrenheit - 32) * 5) / 9;
    cout << "Temperature in Celsius is: " << temperatureCelsius << "\n\n";
    return temperatureCelsius;
}

void ReturnExample()
{
    int result = 0;
    int input;

    cout << "Insert number between 0 and 100: ";
    cin >> input;

    cout << "Your number is: " << input;

    input = DoubleAmount(input);
    cout << "\nDouble amount of your number is: " << input << "\n\n";
}

int DoubleAmount(int input)
{
    if (input <= 100 && input > 0)
        return input * 2;
    else
        return -1;
    cout << "The following code will not work, because it's after word return!" << endl;
}

void CapacityOfCuboid(int lenght, int width, int height)
{
    int capacity = lenght * width * height;
    cout << "Capacity of your cuboid is: " << capacity << "\n\n";
}

void InlineFunctionTest()
{
    int number;
    cout << "Insert number: ";
    cin >> number;
    cout << "Triple amount of your number is: " << TrippleAmount(number) << "\n\n";
}

int FibonacciNumber(int numberInSequence)
{
    cout << "Processing fib (" << numberInSequence << ").... ";

    if (numberInSequence < 3)
    {
        cout << "Value at that position is 1\n";
        return 1;
    }
    else
    {
        cout << "Calling FibonacciNumber(" << numberInSequence - 2 << ") a FibonacciNumber(" << numberInSequence - 1 << ").\n";
        return (FibonacciNumber(numberInSequence - 2) + FibonacciNumber(numberInSequence - 1));
    }
}

void FibonacciTest()
{
    int numberInSequence = 0;
    cout << "Please insert your number in Fibbonaci sequence: ";
    cin >> numberInSequence;
    cout << "Value of your number is: " << FibonacciNumber(numberInSequence) << "\n\n";
}

// Exercise page 138
unsigned long int Circumference(unsigned short int lenght, unsigned short int width)
{
    return (lenght + width) * 2;
}

float Exercise9(unsigned short firstNumber, unsigned short secondNumber)
{
    if (secondNumber == 0)
    {
        cout << "You can't divide by zero!" << endl;
        return -1;
    }
    else return firstNumber / secondNumber;
}

void Exercise10()
{
    int firstNumber, secondNumber;

    cout << "Plsease insert two numbers: " << endl;
    cin >> firstNumber;
    cin >> secondNumber;

    cout << "Result after division is: " << Exercise9(firstNumber, secondNumber) << "\n\n";
}

// This function should return result of a power number and user should select base number and also it's power number
int Exercise11()
{
    int baseNumber, powerNumber, result = 0;
    cout << "Please insert your base number: ";
    cin >> baseNumber;
    cout << "Please insert your power number: ";
    cin >> powerNumber;

    if (powerNumber == 0)
        return 1;
    else if (powerNumber == 1)
        return baseNumber;
    else if (powerNumber > 1)
    {
        result = PowerNumber(baseNumber, powerNumber - 1);
    }

    cout << baseNumber << "^" << powerNumber << " = " << result << "\n\n";
    
    return result;
}

int PowerNumber(int baseNumber, int powerNumber)
{
    baseNumber += baseNumber;
    if (powerNumber > 1)
        return PowerNumber(baseNumber, powerNumber - 1);
    else
        return baseNumber;
}
