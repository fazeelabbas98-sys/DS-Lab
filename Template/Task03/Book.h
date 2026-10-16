#pragma once
#include <iostream>
#include <string>
#include "LibraryItem.h"

using namespace std;

class Book : public LibraryItem
{
private:
    string title;
    string author;
    int pages;

public:
    Book(string t = "", string a = "", int p = 0)
    {
        title = t;
        author = a;
        pages = p;
    }

    string getTitle() const
    {
        return title;
    }

    string getAuthor() const
    {
        return author;
    }

    int getPages() const
    {
        return pages;
    }

    void display() override
    {
        cout << "Book Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Pages: " << pages << endl;
    }
};