#pragma once

#include "Employee.h"

class PartTimeEmployee : public Employee {
private:
	double hoursWorked;
	double hourlyRate;
public:
	PartTimeEmployee() : hoursWorked(0.0), hourlyRate(0.0) {}
	PartTimeEmployee(double h, double r) : hoursWorked(h), hourlyRate(r) {}
	void setHours(double h) { hoursWorked = h; }
	void setRate(double r) { hourlyRate = r; }
	double calculateSalary() const override { return hoursWorked * hourlyRate; }
};
