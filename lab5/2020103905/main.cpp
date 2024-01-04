#include <iostream>
#include "person.h"

int main() {
    Person person1; // 默认构造函数
    person1.setName("Steven");
    
    Person person2("James"); // 使用名字初始化
    
    Person person3("LiYin", "20020921558", "2002-09-21", 'M',175.0, 65.0); //使用给定数据初始化

    std::cout << "person1的存储空间大小：" << sizeof(person1) << " bytes" << std::endl;
    std::cout << "person2的存储空间大小：" << sizeof(person2) << " bytes" << std::endl;
    std::cout << "person3的存储空间大小：" << sizeof(person3) << " bytes" << std::endl;

    return 0;
}