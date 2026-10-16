#pragma once
#include "Employee.h"

class PartTimeEmployee : public Employee
{
private:
    double hoursWorked;
    double hourlyRate;

public:
    PartTimeEmployee(double hours, double rate)
    {
        hoursWorked = hours;
        hourlyRate = rate;
    }

    double calculateSalary() override
    {
        return hoursWorked * hourlyRate;
    }
};