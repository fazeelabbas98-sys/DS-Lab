#pragma once
#include <string>
#include <iostream>

class Book {
private:
	std::string title;
	std::string author;
	int pages;
public:
	Book() : title(), author(), pages(0) {}
	Book(const std::string& t, const std::string& a, int p) : title(t), author(a), pages(p) {}
	const std::string& getTitle() const { return title; }
	const std::string& getAuthor() const { return author; }
	int getPages() const { return pages; }
	void display() const { std::cout << "Book: " << title << " by " << author << " (" << pages << " pages)\n"; }
};
