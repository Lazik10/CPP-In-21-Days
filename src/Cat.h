#pragma once
#include <string>
#include <iostream>

class Cat
{
public:
    // Ctor
    Cat();
    Cat(int age, int wight);
    Cat(std::string name);
    // Copy ctor
    Cat(Cat&);
    // Destructor
    ~Cat();

    Cat PassingByObject(Cat cat);
    Cat* PassingByPointerToObject(Cat* cat);
    const Cat& PassingByReference(const Cat& cat);

    inline int GetAge() const { return _age; };
    inline void SetAge(int age) { _age = age; };
    inline int GetHeight() const { return this->_height; };
    inline void SetHeight(int height) { this->_height = height; };
    inline int GetWeight() const { return _weight; };

    // Methods used below are only used in examples what we should never do
    Cat& CreatCatAtHeap();

private:
    int _age;
    int _height;
    int _weight;
    std::string _name;
};