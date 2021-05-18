#pragma once
#include <iostream>

// Interface of class Animal
class Animal
{
public:
    enum class Gender
    {
        MALE,
        FEMALE
    };

    enum class Health
    {
        HEALTHY,
        SICK,
    };

    // default constructor
    Animal();
    // more constructors with different number of parameters
    Animal(int age);
    Animal(int age, int weight);
    Animal(int age, int weight, int height);
    // destructor
    virtual ~Animal();

    // copy constructor
    Animal(const Animal& animal);

    // clone (copy)
    virtual Animal* Clone() { return new Animal(*this); };

    // get methods
    inline int GetAge() const { return m_age; }
    inline int GetWeight() const { return m_weight; }
    inline int GetHeight() const { return m_height; }
    inline Gender GetGender() const { return m_gender; }
    inline Health IsHealthy() const { return m_health; }
    // set methods
    inline void SetAge(int age) { this->m_age = age; };
    inline void SetWeight(int weight) { this->m_weight = weight; };
    inline void SetHeight(int height) { this->m_height = height; };
    inline void SetGender(Gender gender) { this->m_gender = gender; };
    inline void SetHealth(Health health) { this->m_health = health; };

    virtual void MakeSound() const;
    void Sleep() const;

    friend std::ostream& operator<<(std::ostream& output, const Animal& animal);

protected:
    void MakeRandomGender();

    int m_age;
    int m_weight;
    int m_height;
    Gender m_gender;
    Health m_health;
};