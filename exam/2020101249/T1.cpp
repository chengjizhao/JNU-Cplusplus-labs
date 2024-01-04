//定义一个基类Person，包含私有成员变量name和age，以及公有成员函数void display()用于输出姓名和年龄。
//从Person派生一个子类Student，增加私有成员变量studentID，并重写display函数以输出姓名、年龄和学生ID。
//在main函数中创建一个Person对象和一个Student对象，分别设置它们的姓名、年龄和学生ID，
//然后调用display函数显示信息，画UML图

#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string name;
    int age;

public:
    Person(const string &n, int a) : name(n), age(a) 
    {

    }

    virtual void display()
     {
        cout << name << ", " << age;
    }
};

class Student : public Person 
{
private:
    string studentID;
public:
    Student(const string &n, int a, const string &id) : Person(n, a), studentID(id) 
    {

    }

    void display() {
        Person::display();
        cout << ", " << studentID;
    }
};

int main() {
    Person *p1 = new Person("P", 5);
    Person *p2 = new Student("S", 10, "123456");
    p1->display();
    cout << endl;
    p2->display();
    cout << endl;
    return 0;
}