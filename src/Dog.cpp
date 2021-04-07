#include "Dog.h"


Dog::Dog() :
    m_race(Race::LABRADOR)
{
    std::cout << "Calling dog's constructor!\n";
}

Dog::Dog(int age, int weight, int height, Health health, Gender gender, Race race) :
    Animal(age, weight, height), m_race(race)
{
    // we can't initialize these two data members in initialization process, because our base class Animal
    // has no constructor which would take all these arguments
    m_health = health;
    m_gender = gender;
}

Dog::~Dog()
{

}

Dog::Dog(const Dog& dog) :
    Animal(dog), m_race(Race::LABRADOR)
{
    std::cout << "Copy constructor of a dog\n";
}

Dog* Dog::Clone()
{
    return new Dog(*this);
}

void Dog::ShakeTail() const
{
    std::cout << "The dog is shaking it's tail.\n";
}

void Dog::AskForFood() const
{
    std::cout << "The dog is askign for food!\n";
}

void Dog::MakeSound() const
{
    std::cout << "Bark, Bark, Bark...\n";
}
