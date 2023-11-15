/*
+---------------------+
|       Person        |
+---------------------+
|  - name             |
|  - age              |
|  v displayInfo()    |
+---------------------+
        |
+---------------------+
|      Student        |
+---------------------+
|  - name             |
|  - age              |
|  - studentId        |
|  v displayInfo()    |
+---------------------+


*/
#include <iostream>

// 基类 Person
class Person {
public:
    std::string name;
    int age;

    // 虚函数
    virtual void displayInfo() {
        std::cout << "Person - Name: " << name << ", Age: " << age << std::endl;
    }
};

// 派生类 Student
class Student : public Person {
public:
    int studentId;

    // 虚函数的重写
    void displayInfo() override {
        std::cout << "Student - Name: " << name << ", Age: " << age << ", ID: " << studentId << std::endl;
    }
};

int main() {
    // 创建 Student 对象
    Student studentObject;
    studentObject.name = "Alice";
    studentObject.age = 20;
    studentObject.studentId = 12345;

    // 输出对象成员变量的地址
    std::cout << "Address of name: " << &studentObject.name << std::endl;
    std::cout << "Address of age: " << &studentObject.age << std::endl;
    std::cout << "Address of studentId: " << &studentObject.studentId << std::endl;

    // 虚函数表地址（仅供参考，不同编译器可能有不同实现）
    uintptr_t* vptrAddr = reinterpret_cast<uintptr_t*>(&studentObject);
    std::cout << "Address of vptr: " << reinterpret_cast<void*>(*vptrAddr) << std::endl;

    // 调用虚函数
    studentObject.displayInfo();

    return 0;
}
