#pragma once
#include <string>
#include <iostream>
#include "Animal.h"

class Cat : public Animal
{
public:
    // Ctor
    Cat();
    Cat(int age);
    Cat(int age, int wight);
    Cat(std::string name);
    // Copy ctor
    Cat(const Cat& cat);
    // Clone
    Cat* Clone() override;
    // Destructor
    virtual ~Cat();

    Cat PassingByObject(Cat cat);
    Cat* PassingByPointerToObject(Cat* cat);
    const Cat& PassingByReference(const Cat& cat);

    // Setters and Getters
    inline int GetAge() const { return _age; };
    inline void SetAge(int age) { _age = age; };
    inline int GetHeight() const { return this->_height; };
    inline void SetHeight(int height) { this->_height = height; };
    inline int GetWeight() const { return _weight; };
    inline void SetKittens(int num_of_kittens) { *_number_of_kittens = num_of_kittens; };
    inline int GetKittens() const { return *_number_of_kittens; };

    // Operators overloading
    // return_type, operator name and actuall operator sign and parametr what we want to add
    // i.e. Cat operator+(Cat & cat) 
    Cat& operator=(const Cat& cat);
    const Cat& operator++();
    const Cat& operator++(int);
    const Cat& operator--();
    const Cat& operator--(int);
    // when adding, substracting, dividing or multyplying we just need to return 
    // new object with members changed accorgingly
    Cat operator+(const Cat& cat);
    Cat operator-(const Cat& cat);
    Cat operator/(const Cat& cat);
    Cat operator*(const Cat& cat);
    bool operator==(const Cat& cat);
    // conversion to another data type
    operator unsigned short();

    void MakeSound() const override;
    void Eat() const;
    void Sleep() const;

    // Methods used below are only used in examples what we should never do
    Cat& CreatCatAtHeap();

    static int number_of_cats;
private:
    int _age;
    int _height;
    int _weight;
    std::string _name;

    int* _number_of_kittens;
};