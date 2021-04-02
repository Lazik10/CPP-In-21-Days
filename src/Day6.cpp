#include <iostream>
#include "Day6.h"
#include "Animal.h"

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