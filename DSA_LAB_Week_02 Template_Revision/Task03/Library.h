#pragma once
#include <iostream>
#include <string>
#include "Book.h"
#include "Newspaper.h"
#include "SearchSort.h"

using namespace std;

class Library
{
private:
    Book books[100];
    Newspaper newspapers[100];

    int bookCount;
    int newspaperCount;

public:
    Library()
    {
        bookCount = 0;
        newspaperCount = 0;
    }

    void addBook(const Book& book)
    {
        if (bookCount < 100)
        {
            books[bookCount] = book;
            bookCount++;
        }
        else
        {
            cout << "Book storage is full." << endl;
        }
    }

    void addNewspaper(const Newspaper& newspaper)
    {
        if (newspaperCount < 100)
        {
            newspapers[newspaperCount] = newspaper;
            newspaperCount++;
        }
        else
        {
            cout << "Newspaper storage is full." << endl;
        }
    }

    void displayCollection()
    {
        cout << "\n--- Books ---\n";

        for (int i = 0; i < bookCount; i++)
        {
            books[i].display();
            cout << endl;
        }

        cout << "--- Newspapers ---\n";

        for (int i = 0; i < newspaperCount; i++)
        {
            newspapers[i].display();
            cout << endl;
        }
    }

    void sortBooksByPages()
    {
        selectionSort(books, bookCount,
            [](const Book& a, const Book& b)
            {
                return a.getPages() < b.getPages();
            });
    }

    void sortNewspapersByEdition()
    {
        selectionSort(newspapers, newspaperCount,
            [](const Newspaper& a, const Newspaper& b)
            {
                return a.getEdition() < b.getEdition();
            });
    }

    Book* searchBookByTitle(string title)
    {
        int index = linearSearch(
            books, bookCount, title,
            [](const Book& b)
            {
                return b.getTitle();
            });

        if (index != -1)
        {
            return &books[index];
        }

        return nullptr;
    }

    Newspaper* searchNewspaperByName(string name)
    {
        selectionSort(newspapers, newspaperCount,
            [](const Newspaper& a, const Newspaper& b)
            {
                return a.getName() < b.getName();
            });

        int index = binarySearch(
            newspapers, newspaperCount, name,
            [](const Newspaper& n)
            {
                return n.getName();
            });

        if (index != -1)
        {
            return &newspapers[index];
        }

        return nullptr;
    }
};