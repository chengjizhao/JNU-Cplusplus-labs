#include "person.h"
#include <iostream>

int main() {
 person p1;  
 person p2("Walter");  
 person p3("Walter", "2224242001XXXX", "2001.XX.XX", "male",167,70); 
 std::cout << "Size of p1: " << sizeof(p1) << " bytes" << std::endl;
 std::cout << "Size of p2: " << sizeof(p2) << " bytes" << std::endl;
 std::cout << "Size of p3: " << sizeof(p3) << " bytes" << std::endl;

 return0;
}