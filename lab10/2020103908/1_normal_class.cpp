/*
+---------------------+
|       Person        |
+---------------------+
|      name           |
+---------------------+
|       age           |
+---------------------+
|    printInfo()      |
+---------------------+
*/
#include <iostream>

class Person {
public:
    // 成员变量
    std::string name;
    int age;

    // 成员函数
    void printInfo() {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

int main() {
    // 创建 Person 对象
    Person personObject;

    // 输出对象成员变量的地址
    std::cout << "Address of name: " << &personObject.name << std::endl;
    std::cout << "Address of age: " << &personObject.age << std::endl;

    // 输出对象成员函数的地址
    typedef void (Person::*MemberFunctionPointer)();
    MemberFunctionPointer functionPtr = &Person::printInfo;
    std::cout << "Address of printInfo function: " << reinterpret_cast<void*>(functionPtr) << std::endl;

    return 0;
}
