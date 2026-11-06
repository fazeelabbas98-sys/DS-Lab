#pragma once

#include "Employee.h"

class FullTimeEmployee : public Employee {
private:
	double fixedSalary;
public:
	FullTimeEmployee() : fixedSalary(0.0) {}
	explicit FullTimeEmployee(double s) : fixedSalary(s) {}
	void setSalary(double s) { fixedSalary = s; }
	double calculateSalary() const override { return fixedSalary; }
};
