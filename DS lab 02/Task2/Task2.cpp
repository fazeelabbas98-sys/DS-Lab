#include <iostream>
#include "FullTimeEmployee.h"
#include "PartTimeEmployee.h"

int main() {
	FullTimeEmployee fte(5000.0);
	PartTimeEmployee pte(80.0, 25.0);

	std::cout << "Full-time salary: " << fte.calculateSalary() << std::endl;
	std::cout << "Part-time salary: " << pte.calculateSalary() << std::endl;

	return 0;
}
