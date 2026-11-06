#pragma once
#include "Employee.h"

class FullTimeEmployee : public Employee
{
private:
    double fixedSalary;

public:
    FullTimeEmployee(double salary)
    {
        fixedSalary = salary;
    }

    double calculateSalary() override
    {
        return fixedSalary;
    }
};