#include "Day8.h"
#include <iostream>

typedef unsigned short int USHORT;

void Day8()
{
    AdressSymbolExample();
    PointerExample();
    PointersAndAdresses();
    NewAndDelete();
    CreatingAndDeletingObjectsInJunkyard();
    AccessToDataMembers();
    Exercise17();
}

void AdressSymbolExample()
{
    int shortNumber = 5;
    int longNumber = 65535;
    int minusNumber = -65635;

    std::cout << "Short number is: " << shortNumber << "\t and its adress is: " << &shortNumber << std::endl;
    std::cout << "Long number is: " << longNumber << "\t and its adress is: " << &longNumber << std::endl;
    std::cout << "Minus number is: " << minusNumber << "\t and its adress is: " << &minusNumber << std::endl << std::endl;
}

void PointerExample()
{
    using std::cout;

    USHORT myAge = 5;
    USHORT * pAge = &myAge;

    cout << "My age is: " << myAge << "\n";
    cout << "*pAge is " << *pAge << "\n";

    cout << "Set pAge to 7.";
    *pAge = 7;

    cout << "\n*pAge is: " << *pAge << "\n";
    cout << "MyAge is: " << myAge << "\n";

    cout << "Set MyAge to 9.\n";
    myAge = 9;
    cout << "MyAge is: " << myAge << " and *pAge is: " << *pAge << "\n\n";
}

void PointersAndAdresses()
{
    using std::cout;

    unsigned short int my_age = 5, your_age = 10;
    // pointer
    unsigned short int* p_my_age = &my_age;
    unsigned short int* p_your_age = &your_age;

    cout << "\nMy age: \t\t" << my_age << "\t\tYour age: " << your_age << "\n";
    cout << "&My age: \t" << &my_age << "\t&Your age: " << &your_age << "\n";

    cout << "Pointer to my age: " << p_my_age << "\n";
    cout << "Pointer to your age: " << p_your_age << "\n";

    cout << "Switching pointer p_my_age to your_age variable!\n";
    p_my_age = &your_age;
    cout << "p_my_age is pointing to adress: " << p_my_age << "\n";
    cout << "Dereference of pointer p_my_age is: " << *p_my_age << "\n";
}

void NewAndDelete()
{
    int local_variable = 6;
    int* p_local_variable = &local_variable;
    int* p_junkyard = new int;
    *p_junkyard = 7;

    std::cout << "\n\nLocal variable: " << local_variable << "\n";
    std::cout << "Dereference of pointer to local variable: " << *p_local_variable << "\n";
    std::cout << "Dereference of pointer to junkyard variable: " << *p_junkyard << "\n";

    delete p_junkyard;

    p_junkyard = new int;
    *p_junkyard = 9;
    std::cout << "Dereference of pointer to junkyard variable: " << *p_junkyard << "\n";

    delete p_junkyard;
}

void MemoryLeakExample()
{
    unsigned short int* p_pointer = new unsigned short int;
    *p_pointer = 72;
    // delete p_pointer;
    p_pointer = new unsigned short int; // p_pointer is pointing to new adress 
    // and the old one is still storing the number 72, at this point we won't have access to that number ever again
    *p_pointer = 82;
}


Cat::Cat()
{
    // constructor
    std::cout << "Calling cat's constructor!\n";
    _age = 5;
    _name = "Cat";
}

Cat::Cat(std::string name)
{
    _name = name;
}

Cat::~Cat()
{
    // destructor
    std::cout << "Calling " << _name << "'s destructor!\n";
}

void CreatingAndDeletingObjectsInJunkyard()
{
    std::cout << "\n\nCreating cat Maya!\n";
    Cat maya;
    std::cout << "Cat * p_Amaunet = new Cat;\n";
    Cat* p_Amaunet = new Cat;
    std::cout << "Delete p_Amaunet\n";
    delete p_Amaunet;
    std::cout << "Pay attention to Maya destructor\n";
}

void AccessToDataMembers()
{
    Cat maya("Maya");
    maya.SetAge(5);
    std::cout << "\n\nMaya's age is: " << maya.GetAge() << "\n";

    Cat* micka = new Cat("Micka");
    micka->SetAge(10);
    std::cout << "Micka's age is: " << micka->GetAge() << "\n";

    std::cout << "Set Micka's age to 20.\n";
    (*micka).SetAge(20);
    std::cout << "Micka's age is now: " << (*micka).GetAge() << "\n";
    delete micka;
}

void ConstPointers()
{
    // 1 - Pointer to constant variable, we can't change the variable
    const int * pointer1 = nullptr;
    // 2 - Constant pointer, we can't change the adress this pointer is pointing to 
    int* const pointer2 = nullptr;
    // 3 - Both cases above together
    const int* const pointer3 = nullptr;

    int new_variable = 0;

    // 1 - *pointer1 = new_variable; - This will not work!!!
    pointer1 = &new_variable;
    // 2 - pointer2 = &new_variable; - This will not work!!!
}

void Exercise17()
{
    unsigned short your_age = 29;
    unsigned short* p_your_age = &your_age;
    *p_your_age = 50;
    std::cout << "\n\nYour age is: " << your_age << "\n";

    int* p_variable = new int;
    *p_variable = 10;
    std::cout << "Value of p_variable is: " << *p_variable << "\n";
    delete p_variable;
}