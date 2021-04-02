#include "Cat.h"

Cat::Cat()
{
    // constructor
    std::cout << "Calling cat's constructor!\n";
    _age = 5;
    _name = "Cat";
}

Cat::Cat(int age, int weight)
{
    _age = age;
    _weight = weight;
    _height = 0;
}

Cat::Cat(std::string name)
{
    _name = name;
}

Cat::Cat(Cat&)
{
    std::cout << "Calling Cat's copy ctor\n";
}

Cat::~Cat()
{
    // destructor
    std::cout << "Calling " << _name << "'s destructor!\n";
}

Cat Cat::PassingByObject(Cat cat)
{
    std::cout << "Cat's Function Passing by object calling\n";
    return cat;
}

Cat* Cat::PassingByPointerToObject(Cat* cat)
{
    std::cout << "Cat's Function Passing by pointer to object calling\n";
    return cat;
}

const Cat& Cat::PassingByReference(const Cat& cat)
{
    std::cout << "Cat's Function Passing by reference calling\n";
    cat.GetAge();
    // Can't change Cat's age, because this function is const and object in argument is also const
    //cat.SetAge(8);
    return cat;
}

Cat& Cat::CreatCatAtHeap()
{
    Cat* p_cat = new Cat(10, 20);
    return *p_cat;
}
