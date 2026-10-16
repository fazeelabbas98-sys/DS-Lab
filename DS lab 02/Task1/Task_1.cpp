#include <iostream>
#include "Circle.h"
#include "Rectangle.h"

int main() {
	Circle c(5.0);
	Rectangle r(4.0, 3.0); 

	std::cout << "Area of circle (r=5): " << c.area() << std::endl;
	std::cout << "Area of rectangle (4x3): " << r.area() << std::endl;

	return 0;
}
