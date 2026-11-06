#pragma once
#include <string>
#include <iostream>

class Newspaper {
private:
	std::string name;
	std::string date;
	std::string edition;
public:
	Newspaper() : name(), date(), edition() {}
	Newspaper(const std::string& n, const std::string& d, const std::string& e) : name(n), date(d), edition(e) {}
	const std::string& getName() const { return name; }
	const std::string& getDate() const { return date; }
	const std::string& getEdition() const { return edition; }
	void display() const { std::cout << "Newspaper: " << name << " Date: " << date << " Edition: " << edition << "\n"; }
};
