#include <iostream>
#include "Course.h"
#include "OnlineCourse.h"
#include "OfflineCourse.h"
using namespace std;

int main()
{
    OnlineCourse online(8, 3);
    OfflineCourse offline(2, 4);

    Course* course1 = &online;
    Course* course2 = &offline;

    cout << "===== Course Details =====" << endl << endl;

    course1->duration();

    cout << endl;

    course2->duration();

    return 0;
}