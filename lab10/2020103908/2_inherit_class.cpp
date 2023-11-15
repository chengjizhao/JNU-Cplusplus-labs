/*
+---------------------+
|      Person         |
+---------------------+
|  - name             |
|  - age              |
|  - printInfo()      |
+---------------------+
        |
+---------------------+
|      Student        |
+---------------------+
|  - studentId        |
|  - printStudentInfo()|
+---------------------+
*/


#include <iostream>

// 基类 Person
class Person {
public:
    // 基类成员变量
    std::string name;
    int age;

    // 基类成员函数
    void printInfo() {
        std::cout << "Person - Name: " << name << ", Age: " << age << std::endl;
    }
};

// 派生类 Student
class Student : public Person {
public:
    // 派生类新增成员变量
    int studentId;

    // 派生类新增成员函数
    void printStudentInfo() {
        std::cout << "Student - ID: " << studentId << std::endl;
    }
};

int main() {
    // 创建 Student 对象
    Student studentObject;

    // 输出对象成员变量的地址
    std::cout << "Address of name: " << &studentObject.name << std::endl;
    std::cout << "Address of age: " << &studentObject.age << std::endl;
    std::cout << "Address of studentId: " << &studentObject.studentId << std::endl;

    // 输出对象成员函数的地址
    typedef void (Person::*PersonFunctionPointer)();
    typedef void (Student::*StudentFunctionPointer)();

    PersonFunctionPointer personFunctionPtr = &Person::printInfo;
    std::cout << "Address of Person::printInfo function: " << reinterpret_cast<void*>(personFunctionPtr) << std::endl;

    StudentFunctionPointer studentFunctionPtr = &Student::printStudentInfo;
    std::cout << "Address of Student::printStudentInfo function: " << reinterpret_cast<void*>(studentFunctionPtr) << std::endl;

    return 0;
}
