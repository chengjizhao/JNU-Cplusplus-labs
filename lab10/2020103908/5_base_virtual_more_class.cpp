/*
+---------------------+
|      Person         |
+---------------------+
|  - name             |
|  - age              |
|  v displayInfo()    |
+---------------------+
        |
+---------------------+
|      Student        |
+---------------------+
|  - studentId        |
|  v displayStudentInfo() |
+---------------------+
*/
#include <iostream>

class Person {
public:
    std::string name;
    int age;

    // 虚函数
    virtual void displayInfo() {
        std::cout << "Person - Name: " << name << ", Age: " << age << std::endl;
    }
};

class Student : public Person {
public:
    int studentId;

    // 新的虚函数
    virtual void displayStudentInfo() {
        std::cout << "Student - ID: " << studentId << std::endl;
    }
};

int main() {
    // 创建派生类对象
    Student studentObj;
    studentObj.name = "John Doe";
    studentObj.age = 20;
    studentObj.studentId = 12345;

    // 输出内存大小
    std::cout << "Size of Student object: " << sizeof(studentObj) << " bytes" << std::endl;

    // 输出对象地址
    std::cout << "Address of Student object: " << &studentObj << std::endl;

    return 0;
}
