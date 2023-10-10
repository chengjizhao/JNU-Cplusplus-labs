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
//explain
//根据输出结果显示，每个Person对象占用136字节的存储空间。这可能是由于编译器对类进行了内存对齐。
//根据输出结果，假设每个Person对象的成员变量按照8字节对齐。因此，即使我们只有一个名字（string类型）作为公共成员变量，其他5个私有成员变量也会影响对象的大小。
//对于string类型，它通常包含指向实际字符串数据的指针、字符串长度和其他一些辅助信息，因此它的大小取决于实际存储的字符串内容和额外的元数据。
//另外，int类型的成员变量通常占用4个字节的内存空间。因此，在这种情况下，除了名字（string类型），其他5个成员变量各自需要8个字节的内存空间，导致每个Person对象占用136字节的存储空间。
