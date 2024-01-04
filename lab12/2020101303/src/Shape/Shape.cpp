#include "Shape.h"
#include <cmath>
#define PI 3.1415926536
Circle::Circle(double radius) {
	this->radius = radius;
}

double Circle::get_area() {
	return PI * pow(radius, 2);
}

double Circle::get_perimeter() {
	return 2 * PI * radius;
}

Rectangle::Rectangle(double width, double height) {
	this->width = width;
	this->height = height;
}

double Rectangle::get_perimeter() {
	return (height + width) * 2;
}

double Rectangle::get_area() {
	return height * width;
}