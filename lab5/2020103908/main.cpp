
#include <iostream>
#include "person.h"

int main() {
    person p1;  // 使用默认构造函数创建对象p1
    std::cout << "p1的存储空间大小：" << sizeof(p1) << " 字节" << std::endl;

    person p2("Alice");  // 使用带名字参数的构造函数创建对象p2
    std::cout << "p2的存储空间大小：" << sizeof(p2) << " 字节" << std::endl;

    person p3("Bob", "123456789", "2000-01-01", "Male", 180, 70);  // 使用带所有属性参数的构造函数创建对象p3
    std::cout << "p3的存储空间大小：" << sizeof(p3) << " 字节" << std::endl;

    return 0;
}
