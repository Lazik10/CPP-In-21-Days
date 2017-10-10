#include <iostream>
#include "Day6.h"

void Day6()
{
    // Make a new animal
    Animal animal;
    // since we didn't initialize variable myAge in default constructor nor in the private part of class interface we will get random result
    // based on what thrash is stored at the adress of myAge, to fix this we can use Animal animal(10);
    std::cout << "Your animal is " << animal.GetAge() << " year(s) old." << std::endl;
    // Set age
    animal.SetAge(10);
    // Now we can see the correct age of our animal
    std::cout << "Your animal is " << animal.GetAge() << " year(s) old." << std::endl;

    Exercise12();
}

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
}

void Animal::MakeRandomGender()
{
}

// Exercises

Employee::Employee()
{
}

Employee::Employee(int age, int salary, int yearsInCompany)
{
    myAge = age;
    mySalary = salary;
    myNumberOfYears = yearsInCompany;
}

Employee::~Employee()
{
}

int Employee::SalaryInThousands() const
{
    return mySalary / 1000;
}

void Employee::SetAge(int age)
{
    myAge = age;
}

void Employee::SetSalary(int salary)
{
    mySalary = salary;
}

void Employee::SetYearsInCompany(int numberOfYears)
{
    myNumberOfYears = numberOfYears;
}


void Exercise12()
{
    Employee Damon;
    Employee Stephan;

    Damon.SetAge(25);
    Damon.SetSalary(25000);
    Damon.SetYearsInCompany(5);

    Stephan.SetAge(30);
    Stephan.SetSalary(30000);
    Stephan.SetYearsInCompany(10);

    std::cout << "Damon is " << Damon.GetAge() << " years old. His salary is " << Damon.GetSalary() << " and is " << Damon.GetYearsInCompany() << " years in our company." << std::endl;
    std::cout << "Stephan is " << Stephan.GetAge() << " years old. His salary is " << Stephan.GetSalary() << " and is " << Stephan.GetYearsInCompany() << " years in our company." << std::endl;
}