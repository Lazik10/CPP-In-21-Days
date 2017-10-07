#include <iostream> 
#include "Day4.h"

using namespace std;

// Expressions and commands

void Day4()
{
    IncrementNumber(5);
    DecrementNumber(5);
    IfFunctionDemonstration();
    LogicOperators();
    ConditionalOperator();
    Exercise6();
    Exercise7();
    Exercise8();
}

// Incrementation ++
void IncrementNumber(int num)
{
    // There are two possible ways to increment number - (Postfix) num++ or (Prefix) ++num
    // In postfix, number is evaluated after it's assigning on the other hand in prefix before it's assigning
    int incrPostfixNumber, incrPrefixNumber = 0;

    // incrPostfixNumber will be equal to original num value, because incrementation happens after assigning to incrPostfixNumber
    incrPostfixNumber = num++;
    cout << "Number incremented with postfix is: " << incrPostfixNumber << endl;

    // Since num is already increased by one and in this case incrementation is in prefix form, num is going to increase itself by one before assigning to incrPrefixNumber
    // so incrPrefixNumber is bigger than incrPostfixNumber by 2
    incrPrefixNumber = ++num;
    cout << "Number incremented with postfix is: " << incrPrefixNumber << endl;
}

// Decrementation --
void DecrementNumber(int num)
{
    // There are two possible ways to decrement number - (Postfix) num-- or (Prefix) ++num
    int incrPostfixNumber, incrPrefixNumber = 0;

    // This number will be same 
    incrPostfixNumber = num--;
    cout << "Number decremented with postfix is: " << incrPostfixNumber << endl;

    incrPrefixNumber = --num;
    cout << "Number decremented with postfix is: " << incrPrefixNumber << endl;
}

void IfFunctionDemonstration()
{
    cout << "\n\n";
    int scoreArsenal, scoreChelsea = 0;

    cout << "Please insert score of team Arsenal: ";
    cin >> scoreArsenal;

    cout << "Please insert score of team Chelsea: ";
    cin >> scoreChelsea;

    cout << "\n";

    if (scoreArsenal > scoreChelsea)
        cout << "Arsenal won this match!";
    else if (scoreArsenal == scoreChelsea)
        cout << "The match ended with draw.";
    else if (scoreArsenal < scoreChelsea)
        cout << "Chelsea won this match.";
}

void LogicOperators()
{
    cout << "\n\n";
    int scoreArsenal, scoreChelsea = 0;

    cout << "Please insert score of team Arsenal: ";
    cin >> scoreArsenal;

    cout << "Please insert score of team Chelsea: ";
    cin >> scoreChelsea;

    // Example of using AND (&&), OR (||) and NOT (!) operators
    if (scoreArsenal == 1 && scoreChelsea == 1)
        cout << "In this match we saw exactly 1 goal from each team!\n";
    if (scoreArsenal == 3 || scoreChelsea == 3)
        cout << "In this match at least one or both teams scored 3 goals.\n"; 
    if (!(scoreArsenal == 0))
        cout << "Arsenal finally broke the curse and score a goal at Stamford Bridge!\n";
}

void ConditionalOperator()
{
    cout << "\n\n";
    int scoreArsenal, scoreChelsea = 0;

    cout << "Please insert score of team Arsenal: ";
    cin >> scoreArsenal;

    cout << "Please insert score of team Chelsea: ";
    cin >> scoreChelsea;

    (scoreArsenal >= scoreChelsea) ? cout << "Arsenal scored more or equal goals than Chelsea!" : cout << "Chelsea scored more goals in this match!";
}

/// Page 104 Exercises

// 1.) We should write a program which compares two numbers and the bigger one changes to the smaller one
void Exercise6()
{
    cout << "\n\n";
    int number1, number2 = 0;

    cout << "Please instert first number: ";
    cin >> number1;

    cout << "Please insert second number: ";
    cin >> number2;

    if (number1 > number2)
        number1 = number2;
    else
        number2 = number1;

    cout << "First number is now: " << number1 << "\n" << "Second number is now: " << number2 << "\n";
}
 
void Exercise7()
{
    int a, b, c;
    cout << "Please insert three numbers:\n";
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "c: ";
    cin >> c;

    if (c = (a - b))
    {
        cout << "a: " << a << " minus b: " << b << " is equal to c: " << c << endl;
    }
    else cout << "a - b se nerovna c: ";
}

// This function will print nothing, because IF condition (2-2 = 0) is evaluated as zero / false
void Exercise8()
{
    int a = 2, b = 2, c;
    if (c = (a - b))
        cout << "Value of c is: " << c << endl;
}
