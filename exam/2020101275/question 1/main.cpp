#include <iostream>
#include <string>

class Person {
private:
    std::string name;
    int age;

public:
    Person(const std::string& n, int a) : name(n), age(a) {}

    virtual void display() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

class Employee : public Person {
private:
    int empID;

public:
    Employee(const std::string& n, int a, int id) : Person(n, a), empID(id) {}

    void showEmployee() const {
        std::cout << "Employee ID: " << empID << std::endl;
    }
};

class Manager : public Employee {
private:
    std::string department;

public:
    Manager(const std::string& n, int a, int id, const std::string& dept)
        : Employee(n, a, id), department(dept) {}

    void display() const override {
        Employee::display();
        std::cout << "Department: " << department << std::endl;
    }
};

int main() {
    // 创建一个 Manager 对象，设置其姓名、年龄、员工ID和部门
    Manager manager("Han Lee", 37, 2023195, "HR");

    // 调用 display 函数显示信息
    std::cout << "Manager Information:" << std::endl;
    manager.display();

    // 调用 showEmployee 函数显示信息
    std::cout << "\nEmployee Information:" << std::endl;
    manager.showEmployee();

    return 0;
}
