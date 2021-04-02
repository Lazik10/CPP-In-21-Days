#pragma once
#include <iostream>

enum Gender
{
    MALE,
    FEMALE
};

enum Health
{
    HEALTHY,
    SICK,
};

// Interface of class Animal
class Animal
{
public:
    // default constructor
    Animal();
    // more constructors with different number of parameters
    Animal(int age);
    Animal(int age, int weight);
    Animal(int age, int weight, int height);
    // destructor
    ~Animal();

    // get methods
    int GetAge() const { return myAge; }
    int GetWeight() const { return myHealth; }
    int GetHeight() const { return myHeight; }
    bool GetGender() const { return myGender; }

    bool IsHealthy() const { return myHealth; }

    void MakeSound();

    // set methods
    void SetAge(int age);
    void SetWeight(int weight);
    void SetHeight(int height);
    void SetGender(bool gender);

private:
    void MakeRandomGender();

    int myAge;
    int myWeight;
    int myHeight;
    bool myGender;
    bool myHealth;
};