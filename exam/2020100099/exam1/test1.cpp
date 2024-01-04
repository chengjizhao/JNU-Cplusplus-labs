#include <iostream>
#include <string>
using namespace std;

// 定义基类Person
class Person {
private:
    string name;
    int age;
public:
    void setName(string n) {
        name = n;
    }
    void setAge(int a) {
        age = a;
    }
    string getName() {
        return name;
    }
    int getAge() {
        return age;
    }
    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// 从Person派生一个子类Student
class Student : public Person {
private:
    int studentID;
public:
    void setStudentID(int id) {
        studentID = id;
    }
    void display() {
        cout << "Name: " << getName() << ", Age: " << getAge() << ", Student ID: " << studentID << endl;
    }
};

int main() {
    Person p;
    p.setName("Lihua");
    p.setAge(21);
    p.display();
    
    Student s;
    s.setName("xiaoming");
    s.setAge(20);
    s.setStudentID(2020 );
    s.display();
    
    return 0;
}