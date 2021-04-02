#include "Day9.h"
#include "Cat.h"

#include <iostream>

void Day9()
{
    ReferenceExample();
    ReferenceAdressess();
    CatTests();
    PassingByValue();
    PassingByPointer();
    PassingByReference();
    FactorialExample();
    ExampleOfObjectCallings();
    CreatingCatAtHeapExample();

    Excercise18();
}

void ReferenceExample()
{
    int variable = 0;
    int& r_variable = variable;

    std::cout << "Value of variable is: " << variable << "\n";
    std::cout << "Value of r_variable is: " << r_variable << "\n";

    std::cout << "Reference set to 1 \n";
    r_variable = 1;

    std::cout << "Value of variable is " << variable << "\n";
    std::cout << "Value of r_variable is " << r_variable << "\n";
}

void ReferenceAdressess()
{
    int variable = 0;
    int& r_variable = variable;

    std::cout << "Address of variable is: " << &variable << "\n";
    std::cout << "Address of r_variable is: " << &r_variable << "\n";
}

void CatTests()
{
    Cat maya(10, 20);
    Cat& r_maya = maya;

    std::cout << "\n\nMaya is " << maya.GetAge() << " years old." << "\n";
    std::cout << "Reference to Maya is " << r_maya.GetAge() << " years old and her weight is " <<
        r_maya.GetWeight() << "\n";
}

void Switch(int x, int y)
{
    int temp;

    std::cout << "Function Switch. Befor switch, x: " << x << " y: " << y << "\n";

    temp = x;
    x = y;
    y = temp;

    std::cout << "Function Switch. After switch, x: " << x << " y: " << y << "\n";
}

void SwitchByPointers(int* x, int* y)
{
    int temp;

    std::cout << "Function Switch. Befor switch, x: " << *x << " y: " << *y << "\n";

    temp = *x;
    *x = *y;
    *y = temp;

    std::cout << "Function Switch. After switch, x: " << *x << " y: " << *y << "\n";
}

void SwitchByReference(int& x, int& y)
{
    int temp;

    std::cout << "Function Switch. Befor switch, x: " << x << " y: " << y << "\n";

    temp = x;
    x = y;
    y = temp;

    std::cout << "Function Switch. After switch, x: " << x << " y: " << y << "\n";
}

void PassingByValue()
{
    int x = 5, y = 10;
    std::cout << "\n\nFunkce main. Before switch, x: " << x << " y: " << y << "\n";
    Switch(x, y);
    std::cout << "Funkce main. After switch, x: " << x << " y: " << y << "\n";
}

void PassingByPointer()
{
    int x = 5, y = 10;
    std::cout << "\n\nFunkce main. Before switch, x: " << x << " y: " << y << "\n";
    SwitchByPointers(&x, &y);
    std::cout << "Funkce main. After switch, x: " << x << " y: " << y << "\n";
}

void PassingByReference()
{
    int x = 5, y = 10;
    std::cout << "\n\nFunkce main. Before switch, x: " << x << " y: " << y << "\n";
    SwitchByReference(x, y);
    std::cout << "Funkce main. After switch, x: " << x << " y: " << y << "\n";
}

void FactorialExample()
{
    int number, power_two, power_three;
    Errors error = Errors::SUCCESS;

    std::cout << "Please insert number between 0 - 20: " << "\n";
    std::cin >> number;
    
    error = Factorial(number, &power_two, &power_three);

    if (error != Errors::SUCCESS)
    {
        if (error == Errors::ERROR)
            std::cout << "Your number is greater than 20!\n";
    }
    else
    {
        std::cout << "\nNumber " << number << " has 2nd power value of: " << power_two << 
            " and 3rd power value of: " << power_three << "\n";
    }
}

Errors Factorial(int number, int* p_power_two, int* p_power_by_three)
{
    Errors error = Errors::ERROR;

    if (number > 20)
        error = Errors::ERROR;
    else
    {
        *p_power_two = number * number;
        *p_power_by_three = number * number * number;
        error = Errors::SUCCESS;
    }
    return error;
}

void ExampleOfObjectCallings()
{
    std::cout << "Creating new cat Maya\n";
    Cat maya;
    std::cout << "Calling function Passing by object in main\n";
    maya.PassingByObject(maya);
    std::cout << "Calling function Passing by object poiner in main\n";
    maya.PassingByPointerToObject(&maya);
}

// This code showes that will hapen if we create a new object on heap, make a reference to it and then delete 
// the object, the reference still points to the origin object address, but the data stored there were deleted
// and when we try to access that object and it's data members we will get random number stored at that address
void CreatingCatAtHeapExample()
{
    Cat* maya = new Cat(10,20);
    Cat& r_cat = *maya;
    int vek = r_cat.GetAge();
    std::cout << "r_cat is " << vek << " age old.\n";
    std::cout << "&r_cat is " << &r_cat << "\n";
    Cat* p_cat = &r_cat;
    delete p_cat;
    std::cout << "Address of r_cat is: " << &r_cat << "\n";
    //std::cout << "The cat's age is: " << r_cat.GetAge() << "\n";
}

void Excercise18()
{
    int variable = 0;
    std::cout << "Original variable value is: " << variable << "\n";
    int* p_variable = &variable;
    int& r_variable = variable;
    *p_variable = 10;
    std::cout << "Changing variable value with pointer, value is now: " << variable << "\n";
    r_variable = 20;
    std::cout << "Changing variable value with reference, value is now: " << variable << "\n";

    // Only const ptr can point to a const variable
    const int money = 0;
    const int* cp_variable = &money;
}

