#pragma once
#include <iostream>
#include "Course.h"
using namespace std;

class OfflineCourse : public Course
{
private:
    int months;
    int hoursPerDay;

public:
    OfflineCourse(int m, int h)
    {
        months = m;
        hoursPerDay = h;
    }

    void duration() override
    {
        cout << "Offline Course Duration:" << endl;
        cout << "Months: " << months << endl;
        cout << "Hours per day: " << hoursPerDay << endl;
        cout << "Total study hours: "
            << months * 30 * hoursPerDay << endl;
    }
};