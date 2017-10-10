#pragma once

void Day6();

void Exercise12();

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
    bool myHealth = HEALTHY;
};

// Exercise page 171
class Employee
{
public:
    Employee();
    Employee(int age, int salary, int yearsInCompany);
    ~Employee();

    int GetAge() const { return myAge; }
    int GetSalary() const { return mySalary; }
    int GetYearsInCompany() const { return myNumberOfYears; }
    int SalaryInThousands() const;

    void SetAge(int age);
    void SetSalary(int salary);
    void SetYearsInCompany(int numberOfYears);

private:
    int myAge;
    int mySalary;
    int myNumberOfYears;
};