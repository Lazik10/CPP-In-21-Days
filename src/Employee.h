#pragma once

class Employee
{
public:
    Employee();
    Employee(int age, int salary, int yearsInCompany);
    ~Employee();

    int GetAge() const { return _myAge; }
    int GetSalary() const { return _mySalary; }
    int GetYearsInCompany() const { return _myNumberOfYears; }
    int SalaryInThousands() const;

    void SetAge(int age);
    void SetSalary(int salary);
    void SetYearsInCompany(int numberOfYears);

private:
    int _myAge = 0;
    int _mySalary = 0;
    int _myNumberOfYears = 0;
};