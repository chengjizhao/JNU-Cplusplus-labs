#include <iostream>
#include <string>

// 基类Person
class Person {
private:
    std::string name;
    int age;

public:
    Person(const std::string& n, int a) : name(n), age(a) {}

    virtual void display() {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

// 派生类Student
class Student : public Person {
private:
    std::string studentID;

public:
    Student(const std::string& n, int a, const std::string& id) : Person(n, a), studentID(id) {}

    void display() override {
        Person::display();
        std::cout << "Student ID: " << studentID << std::endl;
    }
};

int main() {
    Person p("Yuan", 25);
    Student s("Yu", 20, "S1234");

    p.display();
    s.display();

    return 0;
}