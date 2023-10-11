
#include <iostream>
#include "person.h"

int main() {
    Person p1;  // 使用默认构造函数创建一个Person对象
    Person p2("Alice");  // 使用带名字的构造函数创建一个Person对象
    Person p3("Yuanyuzhou", "320683200210050212", "2002-10-05", 'M', 175.0, 75.0);  // 使用完整构造函数创建一个Person对象

    std::cout << "Size of p1: " << sizeof(p1) << " bytes\n";
    std::cout << "Size of p2: " << sizeof(p2) << " bytes\n";
    std::cout << "Size of p3: " << sizeof(p3) << " bytes\n";

    return 0;
}
