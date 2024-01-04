#include <iostream>
#include <string>

// 基类 Person
class Person {
private:
    std::string name;
    int age;

public:
    Person(const std::string& n, int a) : name(n), age(a) {}

    void display() {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

// 基类 Employee
class Employee : public Person {
private:
    int empID;

public:
    Employee(const std::string& n, int a, int id) : Person(n, a), empID(id) {}

    void showEmployee() {
        std::cout << "Employee ID: " << empID << std::endl;
    }
};

// 子类 Manager
class Manager : public Employee {
private:
    std::string department;

public:
    Manager(const std::string& n, int a, int id, const std::string& dep)
        : Employee(n, a, id), department(dep) {}

    // 重写 display 函数
    void display() {
        Person::display();
        std::cout << "Department: " << department << std::endl;
    }

    // 重写 showEmployee 函数
    void showEmployee() {
        Employee::showEmployee();
        std::cout << "Department: " << department << std::endl;
    }
};

int main() {
    // 创建 Manager 对象
    Manager manager("Holden feng", 21, 12345, "HR");

    // 设置信息
    manager.display();
    manager.showEmployee();

    return 0;
}
