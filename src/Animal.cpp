#include "Animal.h"

Animal::Animal()
{
    std::cout << "Creating new animal" << std::endl;
}

Animal::Animal(int age)
{
    myAge = age;
    MakeRandomGender();
}

Animal::Animal(int age, int weight)
{
    myAge = age;
    myWeight = weight;
    MakeRandomGender();
}

Animal::Animal(int age, int weight, int height)
{
    myAge = age;
    myWeight = weight;
    myHeight = height;
    MakeRandomGender();
}

Animal::~Animal()
{
}

void Animal::MakeSound()
{
    std::cout << "I am making sound!" << std::endl;
}

void Animal::SetAge(int age)
{
    myAge = age;
}

void Animal::SetWeight(int weight)
{
    myWeight = weight;
}

void Animal::SetHeight(int height)
{
    myHeight = height;
}

void Animal::SetGender(bool gender)
{
    gender = MALE;
}

void Animal::MakeRandomGender()
{
}