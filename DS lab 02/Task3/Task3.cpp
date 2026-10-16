#include <iostream>
#include "Book.h"
#include "Newspaper.h"
#include "Library.h"

int main() {
	Book book1("The Catcher in the Rye", "J.D. Salinger", 277);
	Book book2("To Kill a Mockingbird", "Harper Lee", 324);
	Newspaper newspaper1("Washington Post", "2024-10-13", "Morning Edition");
	Newspaper newspaper2("The Times", "2024-10-12", "Weekend Edition");
	Library library;
	library.addBook(book1);
	library.addBook(book2);
	library.addNewspaper(newspaper1);
	library.addNewspaper(newspaper2);
	std::cout << "Before Sorting:\n";
	library.displayCollection();
	library.sortBooksByPages();
	library.sortNewspapersByEdition();
	std::cout << "\nAfter Sorting:\n";
	library.displayCollection();
	Book* foundBook = library.searchBookByTitle("The Catcher in the Rye");
	if (foundBook) {
		std::cout << "\nFound Book:\n";
		foundBook->display();
	} else {
		std::cout << "\nBook not found.\n";
	}
	Newspaper* foundNewspaper = library.searchNewspaperByName("The Times");
	if (foundNewspaper) {
		std::cout << "\nFound Newspaper:\n";
		foundNewspaper->display();
	} else {
		std::cout << "\nNewspaper not found.\n";
	}
	return 0;
}
