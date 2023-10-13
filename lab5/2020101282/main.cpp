#include <iostream>
#include "person.h"

int main() {
    // 创建Person对象并打印占用的存储空间大小
    std::cout << "Size of Person object: " << sizeof(Person) << " bytes" << std::endl;

    // 使用不同的初始化方法创建Person对象
    Person person1;  // 使用默认构造函数
    Person person2("Alice");  // 使用构造函数设置名字
    Person person3("Bob", "1234567890", {2000, 5, 15, 0, 0, 0, 0, 0, -1}, 'M', 180.0, 70.0);  // 使用构造函数设置所有属性

    return 0;
}
