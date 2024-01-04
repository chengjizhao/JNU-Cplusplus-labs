#include <iostream>
#include "person.h"

int main() {
    Person person1;  // 使用默认构造函数
    person1.name = "John Doe";

    Person person2("Alice Smith");  // 使用带有名字参数的构造函数

    Person person3("Bob Johnson", "1234567890", "2001-01-01", "Male", 180.0, 75.5);

    std::cout << "Size of person1 object: " << sizeof(person1) << " bytes" << std::endl;
    std::cout << "Size of person2 object: " << sizeof(person2) << " bytes" << std::endl;
    std::cout << "Size of person3 object: " << sizeof(person3) << " bytes" << std::endl;

    return 0;
}
/*对象的尺寸为176字节。这是因为在大多数编译器中，类的大小通常受对齐和填充的影响。在这个例子中，可能会发生以下对齐和填充：

std::string 类型的成员变量会占用一定的存储空间，其中指针指向动态分配的字符串数据。这可能会导致对齐和填充，使得每个 std::string 成员变量占用的存储空间超过其实际存储的字符串长度。
double 类型的成员变量通常需要对齐到 8 字节边界，因此在填充了额外的空间后才能存储。
对象的大小通常会被对齐到某个较大的边界，以便于访问和处理。
因此，尽管 Person 类的成员变量的实际大小可能小于 40 字节，但由于对齐和填充的原因，对象的尺寸变为 176 字节。*/