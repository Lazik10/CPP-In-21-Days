#pragma once
#include "String.h"

class Employee
{
public:
    Employee();
    Employee(char* name, char* surname, char* address, int salary);
    Employee(int age, int salary, int yearsInCompany);
    ~Employee();

    Employee(const Employee& employee);
    Employee& operator=(const Employee employee);

    int GetAge() const { return _myAge; }
    int GetSalary() const { return _mySalary; }
    int GetYearsInCompany() const { return _myNumberOfYears; }
    int SalaryInThousands() const;
    const String& GetName() const { return m_name; }
    const String& GetSurname() const { return m_surname; }
    const String& GetAddress() const { return m_address; }

    void SetAge(int age);
    void SetSalary(int salary);
    void SetYearsInCompany(int numberOfYears);
    void SetName(const String& name) { m_name = name; };
    void SetSurname(const String& surname) { m_surname = surname; }
    void SetAddress(const String& address) { m_address = address; }

    friend void PrintEmployee(Employee& employee);

private:
    int _myAge = 0;
    int _mySalary = 0;
    int _myNumberOfYears = 0;
    String m_name;
    String m_surname;
    String m_address;
};

void PrintEmployee(Employee& employee);