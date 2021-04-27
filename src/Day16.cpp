#include "Day16.h"
#include "Employee.h"

void Day16()
{
    CreatingEmployee();
}

void CreatingEmployee()
{
    Employee Lazik("Patrik", "Laska", "Trutnov", 10000);
    Lazik.SetSalary(10000);
    String surname = "Lazik";
    Lazik.SetSurname(surname);
    Lazik.SetName("Lazik");

    std::cout << "Employee name is: " << Lazik.GetName().GetString() << std::endl;
    std::cout << "Employee surname is: " << Lazik.GetSurname().GetString() << std::endl;
    std::cout << "Employee address is: " << Lazik.GetAddress().GetString() << std::endl;
    std::cout << "Employee salary is: " << Lazik.GetSalary() << std::endl;
    std::cout << "Employee is working in this company for " << Lazik.GetYearsInCompany() << " year(s)" << std::endl;
    std::cout << "Employee is: " << Lazik.GetAge() << " year(s) old." << std::endl;

    PrintEmployee(Lazik);
}
