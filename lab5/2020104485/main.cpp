#include <iostream>
#include "person.h"

int main() {
 Person p1;
 Person p2("John");
 Person p3("Alice", "1234567890", "1990-01-01", 'F',165.5,60.0);

 std::cout << "Size of p1: " << sizeof(p1) << " bytes" << std::endl;
 std::cout << "Size of p2: " << sizeof(p2) << " bytes" << std::endl;
 std::cout << "Size of p3: " << sizeof(p3) << " bytes" << std::endl;

 return 0;
}
