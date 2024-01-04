#include <iostream>  
#include <string>  
  
// 基类 Person  
class Person {  
protected:  
    std::string name;  
    int age;  
  
public:  
    // 构造函数  
    Person(const std::string& n, int a) : name(n), age(a) {}  
  
    // 公有成员函数，用于显示姓名和年龄  
    virtual void display() const {  
        std::cout << "Name: " << name << ", Age: " << age << std::endl;  
    }  
};  
  
// 派生类 Student  
class Student : public Person {  
private:  
    std::string studentID;  
  
public:  
    // 构造函数  
    Student(const std::string& n, int a, const std::string& id) : Person(n, a), studentID(id) {}  
  
    // 重写 display 函数以输出姓名、年龄和学生ID  
    void display() const override {  
        Person::display(); // 调用基类的 display 函数  
        std::cout << "Student ID: " << studentID << std::endl;  
    }  
};  
  
int main() {  
    // 创建一个 Person 对象并设置其姓名和年龄  
    Person person("Alice", 30);  
    // 创建一个 Student 对象并设置其姓名、年龄和学生ID  
    Student student("Bob", 20, "S123456");  
  
    // 调用 display 函数显示信息  
    person.display();  
    student.display();  
  
    return 0;  
}