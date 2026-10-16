#pragma once
#include <vector>
#include <string>
#include "Book.h"
#include "Newspaper.h"
#include "algorithms.h"

class Library {
private:
	std::vector<Book> books;
	std::vector<Newspaper> newspapers;
public:
	void addBook(const Book& b) { books.push_back(b); }
	void addNewspaper(const Newspaper& n) { newspapers.push_back(n); }
	void displayCollection() const {
		for (const auto& b : books) b.display();
		for (const auto& n : newspapers) n.display();
	}
	void sortBooksByPages() {
		selectionSort<Book>(books, [](const Book& a, const Book& b){ return a.getPages() < b.getPages(); });
	}
	void sortNewspapersByEdition() {
		selectionSort<Newspaper>(newspapers, [](const Newspaper& a, const Newspaper& b){ return a.getEdition() < b.getEdition(); });
	}
	Book* searchBookByTitle(const std::string& title) {
		int idx = linearSearch<Book, std::string>(books, title, [](const Book& b, const std::string& t){ return b.getTitle() == t; });
		if (idx >= 0) return &books[static_cast<size_t>(idx)];
		return nullptr;
	}
	Newspaper* searchNewspaperByName(const std::string& name) {
		int idx = linearSearch<Newspaper, std::string>(newspapers, name, [](const Newspaper& n, const std::string& s){ return n.getName() == s; });
		if (idx >= 0) return &newspapers[static_cast<size_t>(idx)];
		return nullptr;
	}
};
