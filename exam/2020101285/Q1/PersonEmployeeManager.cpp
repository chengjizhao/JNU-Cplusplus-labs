#include <iostream>
#include <string>

// 基类 Person
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

// 基类 Employee
class Employee {
private:
    int empID;

public:
    Employee(int id) : empID(id) {}

    virtual void showEmployee() const {
        std::cout << "Employee ID: " << empID << std::endl;
    }
};

// 派生类 Manager 继承自 Person 和 Employee
class Manager : public Person, public Employee {
private:
    std::string department;

public:
    Manager(const std::string& n, int a, int id, const std::string& dept)
        : Person(n, a), Employee(id), department(dept) {}

    // 重写 display 函数
    void display() const override {
        // 调用基类 Person 的 display 函数
        Person::display();
        std::cout << "Department: " << department << std::endl;
    }

    // 重写 showEmployee 函数
    void showEmployee() const override {
        // 调用基类 Employee 的 showEmployee 函数
        Employee::showEmployee();
    }
};

int main() {
    // 创建一个 Manager 对象
    Manager manager("John Doe", 35, 1234, "Human Resources");

    // 设置信息并调用 display 和 showEmployee 函数显示
    std::cout << "Manager Information:" << std::endl;
    manager.display();
    manager.showEmployee();

    return 0;
}
