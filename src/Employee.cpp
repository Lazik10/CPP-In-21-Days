#include "Employee.h"

Employee::Employee()
{
}

Employee::Employee(int age, int salary, int yearsInCompany)
{
    _myAge = age;
    _mySalary = salary;
    _myNumberOfYears = yearsInCompany;
}

Employee::~Employee()
{
}

int Employee::SalaryInThousands() const
{
    return _mySalary / 1000;
}

void Employee::SetAge(int age)
{
    _myAge = age;
}

void Employee::SetSalary(int salary)
{
    _mySalary = salary;
}

void Employee::SetYearsInCompany(int numberOfYears)
{
    _myNumberOfYears = numberOfYears;
}