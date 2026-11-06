#include <iostream>
#include <iomanip>
#include "Employee.h"
#include "FullTimeEmployee.h"
#include "PartTimeEmployee.h"

using namespace std;

int main()
{
    FullTimeEmployee fullTime(50000);
    PartTimeEmployee partTime(80, 500);

    Employee* emp1 = &fullTime;
    Employee* emp2 = &partTime;

    cout << fixed << setprecision(2);

    cout << "Full-Time Employee Salary: "
        << emp1->calculateSalary() << endl;

    cout << "Part-Time Employee Salary: "
        << emp2->calculateSalary() << endl;


    return 0;
}