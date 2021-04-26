#include "Day15.h"
#include "Cat.h"

void Day15()
{
    StaticMemberExmaple();
    FunctionPointersExample();
    ArrayOfMemberFunctionPointers();
}

void StaticMemberExmaple()
{
    const int MAX_CATS = 5;
    Cat* house_of_cats[MAX_CATS];

    for (int i = 0; i < MAX_CATS; i++)
    {
        house_of_cats[i] = new Cat(i);
        Cat::number_of_cats++;
    }

    for (int i = 0; i < MAX_CATS; i++)
    {
        std::cout << "There is " << Cat::number_of_cats << " cats in the house.\n";
        std::cout << "Deleting Cat with age: " << house_of_cats[i]->GetAge() << std::endl;
        delete house_of_cats[i];
        house_of_cats[i] = nullptr;
        Cat::number_of_cats--;
    }
}

void FunctionPointersExample()
{
    int a, b;
    GetValues(a, b);
    
    // return type (*function name) (arguments) {initialization}
    void (*p_function) (int&, int&) { nullptr }; // declaring function pointer with initialization
    void (*p_function1) (int, int) = nullptr;
    bool end = false;
    int choice;

    while (!end)
    {
        std::cout << "(0) End\n(1)PowTwo\n(2)PowThree\n(3)Exchange\n(4)Change Numbers\n";
        std::cin >> choice;

        switch (choice)
        {
        case 0:
            end = true;
            break;
        case 1:
            p_function = PowTwo;
            break;
        case 2:
            p_function = PowThree;
            break;
        case 3:
            p_function = Exchange;
            break;
        case 4:
            p_function = GetValues;
            break;
        default:
            break;
        }

        if (end)
            break;

        PrintValues(a, b);
        if (p_function)
            p_function(a, b);
        PrintValues(a, b);
    }
}

typedef void (Cat::* p_CF)() const;
void ArrayOfMemberFunctionPointers()
{
    const int max = 3;
    p_CF CatFunctions[max] = {
        &Cat::Eat, &Cat::Sleep, &Cat::MakeSound
    };

    Cat* p_cat = nullptr;
    int choice;
    bool end = false;

    while (!end)
    {
        std::cout << "0 - End, 1 - Eat, 2 - Sleep, 3 - Speak\n";
        std::cin >> choice;
        
        if (choice == end)
            end = true;
        else
        {
            p_cat = new Cat();
            (p_cat->*CatFunctions[choice - 1])();
            delete p_cat;
        }
    }
}

void PowTwo(int& a, int& b)
{
    a *= a;
    b *= b;
}

void PowThree(int& a, int& b)
{
    a = a * a * a;
    b = b * b * b;
}

void Exchange(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void GetValues(int& a, int& b)
{
    std::cout << "Insert first number: \n";
    std::cin >> a;
    std::cout << "Insert second number: \n";
    std::cin >> b;
}

void PrintValues(int a, int b)
{
    std::cout << "Value a is: " << a << " and value b is: " << b << "\n";
}
