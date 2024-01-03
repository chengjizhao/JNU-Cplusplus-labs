#include "Person.h"  
#include <iostream>  
#include <cstdlib> // for size_t type and malloc/free functions  
#include <iomanip> // for setfill and setw for padding output with spaces.   
using namespace std;  // added to simplify the example and allow us to remove all the std:: prefixes.   
// In a real project, it's better to avoid using namespace std and explicitly use the std:: prefix for everything in the std namespace.   
int main() {
    Person p1("Alice", "123456789", "1990-01-01", "Female", 1.70, 55.0);
    Person p2("Bob", "987654321", "2000-02-02", "Male", 1.75, 70.0);
    Person p3("Charlie", "654321098", "1995-03-03", "Male", 1.85, 75.5);

    // 打印每个Person对象的大小  
    cout << "Size of p1: " << sizeof(p1) << " bytes" << endl;
    cout << "Size of p2: " << sizeof(p2) << " bytes" << endl;
    cout << "Size of p3: " << sizeof(p3) << " bytes" << endl;

    return 0;
}