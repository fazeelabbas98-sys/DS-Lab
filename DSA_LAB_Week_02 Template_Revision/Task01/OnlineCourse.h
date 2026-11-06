#pragma once
#include <iostream>
#include "Course.h"
using namespace std;

class OnlineCourse : public Course
{
private:
    int weeks;
    int hoursPerWeek;

public:
    OnlineCourse(int w, int h)
    {
        weeks = w;
        hoursPerWeek = h;
    }

    void duration() override
    {
        cout << "Online Course Duration:" << endl;
        cout << "Weeks: " << weeks << endl;
        cout << "Hours per week: " << hoursPerWeek << endl;
        cout << "Total study hours: "
            << weeks * hoursPerWeek << endl;
    }
};