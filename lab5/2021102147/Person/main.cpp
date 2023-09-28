#include "Person.h"

#include <iostream>

using std::cout, std::endl;
inline void print_person_info(Person& p);

int main() {
	Person p1;
	Person p2("Alice", 1919, 5, 4, 165, 45, "440402200506043183");
	print_person_info(p1);
	cout << endl;
	print_person_info(p2);

	cout << sizeof(Person) << endl;

	return 0;
}

void print_person_info(Person& p) {
	cout << "Name: " << p.name << endl;
	cout << "Birthday: " << p.getBirthYear() << "-" << p.getBirthMonth() << "-" << p.getBirthDay() << endl;
	cout << "Height: " << p.getHeight() << "cm" << endl;
	cout << "Weight: " << p.getWeight() << "kg" << endl;
	cout << "ID Number: " << p.getIDNumber() << endl;
}