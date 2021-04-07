#include "Cat.h"

Cat::Cat() :
    _age(5), _name("Cat"), _weight(0), _height(0)
{
    // constructor
    std::cout << "Calling cat's constructor!\n";

    _number_of_kittens = new int;
}

Cat::Cat(int age) :
    _age(age), _weight(0), _height(0)
{
    _number_of_kittens = new int;
    *_number_of_kittens = 0;
}

Cat::Cat(int age, int weight) :
    _age(age), _weight(weight), _height(0)
{
    _number_of_kittens = new int;
    *_number_of_kittens = 0;
}

Cat::Cat(std::string name)
{
    _name = name;
}

Cat::Cat(const Cat& cat):
    Animal(cat), _age(cat._age),_height(cat._height), _weight(cat._height)
{
    // Shallow copy
    // if our class has pointer member variable it would point to the same location
    // which can lead to an error in our code when we destroy the origin object
    std::cout << "Copy constructor of a cat\n";

    // Deep copy
    // to prevent that we have to do the deep copy, which means for every pointer member variable 
    // we need to create another memory space in heap
    _number_of_kittens = new int;
    *_number_of_kittens = *cat._number_of_kittens;
}

Cat* Cat::Clone()
{
    return new Cat(*this);
}

Cat::~Cat()
{
    // destructor
    std::cout << "Calling " << _name << "'s destructor!\n";

    // set pointer to nullptr and only after that call delete on that pointer!
    _number_of_kittens = nullptr;
    delete _number_of_kittens;
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

Cat& Cat::operator=(const Cat& cat)
{
    if (this == &cat)
        return *this;
    _age = cat._age;
    _weight = cat._weight;
    _height = cat._height;
    _name = cat._name;

    *_number_of_kittens = *cat._number_of_kittens;
    return *this;
}

const Cat& Cat::operator++()
{
    _age++;
    return *this;
}

const Cat& Cat::operator++(int)
{
    _age++;
    return *this;
}

const Cat& Cat::operator--()
{
    _age--;
    return *this;
}

const Cat& Cat::operator--(int)
{
    _age--;
    return *this;
}

Cat Cat::operator+(const Cat& cat)
{
    return Cat(this->_age + cat._age);
}

Cat Cat::operator-(const Cat& cat)
{
    return this->_age - cat._age;
}

Cat Cat::operator/(const Cat& cat)
{
    return this->_age / cat._age;
}

Cat Cat::operator*(const Cat& cat)
{
    return this->_age * cat._age;
}

bool Cat::operator==(const Cat& cat)
{
    return (_age == cat._age);
}

Cat::operator unsigned short()
{
    return (unsigned short int(_age));
}

void Cat::MakeSound() const
{
    std::cout << "Meow, Meow, Meow...\n";
}

Cat& Cat::CreatCatAtHeap()
{
    Cat* p_cat = new Cat(10, 20);
    return *p_cat;
}
