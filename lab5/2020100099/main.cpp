#include <iostream>
#include "person.h"

int main() {
    Person p1;  // 默认构造函数，不传递任何参数
    std::cout << "Size of person1: " << sizeof(Person) << " bytes" << std::endl;

    Person p2("lu");  // 使用一个参数的构造函数
    std::cout << "Size of person2: " << sizeof(Person) << " bytes" << std::endl;

    Person p3("siqi", "1234567890", "2000-01-01", "female", 160, 50);  // 使用所有参数的构造函数
    std::cout << "Size of person3: " << sizeof(Person) << " bytes" << std::endl;

    return 0;
}
