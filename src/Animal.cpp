#include "Animal.h"

Animal::Animal() :
    m_age(1), m_health(Health::HEALTHY), m_height(1),
    m_weight(1), m_gender(Gender::MALE)
{
    std::cout << "Calling animal's constructor!" << std::endl;
}

Animal::Animal(int age) :
    m_age(age)
{
    MakeRandomGender();
}

Animal::Animal(int age, int weight) :
    m_age(age), m_weight(weight)
{
    MakeRandomGender();
}

Animal::Animal(int age, int weight, int height) :
    m_age(age), m_weight(weight), m_height(height)
{
    MakeRandomGender();
}

Animal::~Animal()
{
}

Animal::Animal(const Animal& animal) :
    m_age(animal.m_age)
{

}

void Animal::MakeSound() const
{
    std::cout << "I am making animal sound...\n";
}

void Animal::Sleep() const
{
    std::cout << "The animal is sleeping.\n";
}

void Animal::MakeRandomGender()
{
    m_gender = Gender::MALE;
}