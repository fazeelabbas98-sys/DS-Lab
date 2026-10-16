#pragma once

#include "Shape.h"

class Rectangle : public Shape {
private:
	double length;
	double width;
public:
	Rectangle(double l, double w) : length(l), width(w) {}
	double area() const override { return length * width; }
};
