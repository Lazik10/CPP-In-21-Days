/*
In this day we are going to learn about loops and how to use correct loop for our program flow
*/

#include "Day7.h"
#include <iostream>

#define FOREVER ;;

void Day7()
{
    GoToExample();
    WhileExample();
    BreakAndContinueExample();
    WhileTrueExample();
    DoWhileExample();
    ForExample();
    SwitchExample();
    ForeverLoopExample();

    // Exercises
    Exercise13();
    Exercise14();
    Exercise15();
    Exercise16();
}

// We should be using goto key word at all. This is just for an example how it works.
// There are better loops while, do while or for
void GoToExample()
{
    int value = 0;
    std::cout << "Goto loop example" << "\n\n";

loop: // start of the loop
    value++;
    std::cout << "Value is: " << value << "\n";
    if (value < 5)
        goto loop; // go to the start of the loop

    std::cout << "End. Value is: " << value << "\n\n";
}

// While loop is used for repeating the same block of code until the start condition is true
// if the condition is false the body of the loop will not execute
void WhileExample()
{
    int value = 0;
    std::cout << "While loop example" << "\n\n";

    while (value < 5)
    {
        value++;
        std::cout << "Value is: " << value << "\n";
    }

    std::cout << "End. Value is: " << value << "\n";
}

// Examples of how to exit the loop or go back to the begining of the loop before we reach the end of the loop
void BreakAndContinueExample()
{
    int smallNumber;
    int bigNumber;
    int skipNumber;
    int finishNumber;
    const int MAX_SMALL_NUMBER = 65535;

    std::cout << "\nPlease insert small number: ";
    std::cin >> smallNumber;
    std::cout << "Please insert big number: ";
    std::cin >> bigNumber;
    std::cout << "Please inser skip number: ";
    std::cin >> skipNumber;
    std::cout << "Please insert finish number: ";
    std::cin >> finishNumber;

    std::cout << "\n\n";

    while (smallNumber < bigNumber && smallNumber < MAX_SMALL_NUMBER)
    {
        smallNumber++;

        if (smallNumber % skipNumber == 0)
        {
            std::cout << "Skip minus at number " << smallNumber << std::endl;
            continue;
        }

        if (bigNumber == finishNumber)
        {
            std::cout << "Finish was reached." << std::endl;
            break;
        }

        bigNumber -= 2;
    }

    std::cout << "\nSmall number: " << smallNumber << " Big number: " << bigNumber << "\n\n";
}

// Infinite loop condition, exit due to keyword break
void WhileTrueExample()
{
    int value = 0;

    while (true)
    {
        value++; // it is not the correct place, it should be inside of the if statement, so thi final value won't be bigger than 10
        if (value > 10)
            // correct place for value iteration;
            break;
    }

    std::cout << "Value is: " << value << "\n\n";
}

// Do while loop is used when we need to execute the body of the loop at least once even if the condition is false
void DoWhileExample()
{
    int value = 0;
    std::cout << "How many Hello? : " << std::endl;
    std::cin >> value;

    do
    {
        std::cout << "Hello!" << "\n";
        value--;
    } while (value > 0);

    std::cout << "Value is: " << value << "\n\n";
}

// For loop explanation, with also multiple initialization or iteration
void ForExample()
{
    int value;
    for (value = 0; value < 5; value++)
    {
        std::cout << "Hello!" << "\t";
    }

    std::cout << "Value is: " << value << "\n\n";

    // multiple initialisation
    for (int i = 0, j = 0; i < 5; i++, j++)
    {
        std::cout << "I is: " << i << " J is: " << j << std::endl;
    }
    std::cout << "\n\n";

    // more for loops
    int rows, columns;
    char character;

    std::cout << "How many rows? " << std::endl;
    std::cin >> rows;
    std::cout << "How mamy columns " << std::endl;
    std::cin >> columns;
    std::cout << "Which character should I use? " << std::endl;
    std::cin >> character;
    std::cout << "\n";

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            std::cout << character;
        }

        std::cout << "\n";
    }

    std::cout << "\n\n";

    // FOREVER loop
    for (FOREVER)
    {
        // otherwise we wouldn't leave this loop
        break; 
    }
}

void SwitchExample()
{
    int value;
    std::cout << "Please insert number between 1-5" << std::endl;
    std::cin >> value;

    switch (value)
    {
    case 1:
        std::cout << "Your number is 1.";
        break;
    case 2:
        std::cout << "Your number is 2.";
        break;
    case 3:
        std::cout << "Your number is 3.";
        break;
    case 4:
        std::cout << "Your number is 4.";
        break;
    case 5: std::cout << "Your number is 5."; break; // it can also be at the same line, but I don't recomand to use it this way
    default:
        break;
    }

    std::cout << "\n\n";
}

void ForeverLoopExample()
{
    bool end = false;
    for (FOREVER)
    {
        int option = SelectedMenuOption();
        switch (option)
        {
        case 1:
            ExecuteTask(1);
            end = true;
            break;
        case 2:
            ExecuteTask(2);
            break;
        case 3:
            ExecuteTask(3);
            break;
        case 4:
            ExecuteTask(4);
            end = true;
            break;
        default:
            std::cout << "Please select again." << "\n";
            break;
        }

        if (end == true)
            break;
    }
    std::cout << std::endl << std::endl;
}

int SelectedMenuOption()
{
    int choice;

    std::cout << " ***** MENU *****\n\n";
    std::cout << "Play Game\n";
    std::cout << "Save Game\n";
    std::cout << "Load Game\n";
    std::cout << "Exit Game\n";

    std::cout << "What do you want to do? " << std::endl;
    std::cin >> choice;
    return choice;
}

void ExecuteTask(int task)
{
    if (task == 1)
    {
        std::cout << "Starting Game" << std::endl;
    }
    else if (task == 2)
    {
        std::cout << "Game Saved" << std::endl;
    }
    else if (task == 3)
    {
        std::cout << "Game Loaded" << std::endl;
    }
    else if (task == 4)
    {
        std::cout << "Exiting Game" << std::endl;
    }
}

// Exercise Page 200 and 201
void Exercise13()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            std::cout << "0";
        }

        std::cout << "\n";
    }
}

void Exercise14()
{
    for (int i = 100; i <= 200; i+=2)
    {
        std::cout << "\n" << i;
    }
}

void Exercise15()
{
    int i = 100;

    while (i <= 200)
    {
        std::cout << "\n" << i;
        i += 2;
    }

    std::cout << "\n\n";
}

void Exercise16()
{
    int i = 100;

    do
    {
        std::cout << "\n" << i;
        i += 2;
    } while (i <= 200);

    std::cout << "\n\n";
}