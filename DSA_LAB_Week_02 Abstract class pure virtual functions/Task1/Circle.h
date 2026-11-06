#pragma once

#include "Shape.h"

class Circle : public Shape {
private:
	double radius;
public:
	explicit Circle(double r) : radius(r) {}
	double area() const override { return 3.14159265358979323846 * radius * radius; }
};
