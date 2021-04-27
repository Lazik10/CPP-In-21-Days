#include "Employee.h"

Employee::Employee() :
    _myAge(0), _myNumberOfYears(0), _mySalary(0), m_name(""), m_surname(""), m_address("")
{

}

Employee::Employee(char* name, char* surname, char* address, int salary) :
    _myAge(0), _myNumberOfYears(0), _mySalary(salary), m_name(name), m_surname(surname), m_address(address)
{

}

Employee::Employee(int age, int salary, int yearsInCompany) :
    m_name(""), m_surname(""), m_address("")
{
    _myAge = age;
    _mySalary = salary;
    _myNumberOfYears = yearsInCompany;
}

Employee::~Employee()
{

}

Employee::Employee(const Employee& employee) :
    m_name(employee.GetName()),m_surname(employee.GetSurname()), m_address(employee.GetAddress()),
    _mySalary(employee.GetSalary()), _myAge(employee.GetAge()), _myNumberOfYears(employee.GetYearsInCompany())
{

}

Employee& Employee::operator=(const Employee employee)
{
    if (this == &employee)
        return *this;

    m_name = employee.GetName();
    m_surname = employee.GetSurname();
    m_address = employee.GetAddress();
    _myAge = employee.GetAge();
    _mySalary = employee.GetSalary();
    _myNumberOfYears = employee.GetYearsInCompany();

    return *this;
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

void PrintEmployee(Employee& employee)
{
    employee.m_name = "Lazik test access";
    std::cout << employee.GetName().GetString() << " " << employee.GetSurname().GetString() << "\n";
}
