#include <iostream>
#include "Car.h"
using std::cout;


int main() {
	Suv suv;
	Sedan sedan;
	cout << "Price of SUV: " << suv.calculatePrice() << "\n";
	cout << "Price of sedan:" << sedan.calculatePrice() << "\n";
	return 0;
}