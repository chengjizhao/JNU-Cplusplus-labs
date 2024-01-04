#include <iostream>  
#include <string>  
  
// 定义基类Person  
class Person {  
private:  
    std::string name;  
    int age;  
public:  
    Person(std::string n, int a) : name(n), age(a) {} // 构造函数  
    void display() {  
        std::cout << "Name: " << name << ", Age: " << age << std::endl;  
    }  
};  
  
// 定义派生类Student  
class Student : public Person {  
private:  
    int studentID; 
    std::string name;  
    int age;   
public:  
    Student(std::string n, int a, int sID) : Person(n, a), studentID(sID) {} // 构造函数  
    void display() 
    {  
        std::cout << "Name: " << name << ", Age: " << age << ", Student ID: " << studentID << std::endl;  
    }  
};  
  
int main() {  
    Person person1("John", 25); // 创建Person对象  
    Student student1("Emily", 20, 12345); // 创建Student对象  
    person1.display(); // 显示Person对象的信息  
    student1.display(); // 显示Student对象的信息  
    return 0;  
}