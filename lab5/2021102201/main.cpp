#include <iostream>
#include "person.h"

int main() {
    //默认构造函数的 person 对象
    Person person1;
    std::cout << "person1 占用的存储空间是：" << sizeof(person1) << " 字节" << std::endl;

    //带参数的构造函数的 person 对象
    Person person2("张三", "123456789012345678", "2000-01-01", "男", 180.0, 70.0);
    std::cout << "person2 占用的存储空间是：" << sizeof(person2) << " 字节" << std::endl;

    //拷贝构造函数的 person 对象
    Person person3 = person2;
    std::cout << "person3 占用的存储空间是：" << sizeof(person3) << " 字节" << std::endl;

    return 0;
}
/*
每个Person对象占用的存储空间是128字节。
其中double类型占用8个字节，std::string类型占用28个字节，指针占用 8 个字节。
加起来占用的字节数就是128。
*/