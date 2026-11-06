#pragma once
#include <iostream>
#include <string>
#include "LibraryItem.h"

using namespace std;

class Newspaper : public LibraryItem
{
private:
    string name;
    string date;
    string edition;

public:
    Newspaper(string n = "", string d = "", string e = "")
    {
        name = n;
        date = d;
        edition = e;
    }

    string getName() const
    {
        return name;
    }

    string getDate() const
    {
        return date;
    }

    string getEdition() const
    {
        return edition;
    }

    void display() override
    {
        cout << "Newspaper Name: " << name << endl;
        cout << "Date: " << date << endl;
        cout << "Edition: " << edition << endl;
    }
};