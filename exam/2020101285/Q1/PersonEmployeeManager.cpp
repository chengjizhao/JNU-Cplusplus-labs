#include <iostream>
#include <string>

class Person {
protected:
    std::string name;
    int age;
public:
    Person(const std::string& n, int a) : name(n), age(a) {}
    virtual void display()  {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

class Employee {
protected:
    int empID;
public:
    Employee(int id) : empID(id) {}

    virtual void showEmployee() = 0;

};

class Manager : public Employee, public Person{
private:
    std::string department;

public:
    Manager(const std::string& n, int a, int id, const std::string& dept): Person(n, a), Employee(id), department(dept) {}

    // 重写display函数
    void display() override     {
        std::cout << "Manager Name: " << name << ", Age: " << age <<" ,department: "<<department<< std::endl;
    }

    // 重写showEmployee函数
    void showEmployee() override    {
        std::cout << "Manager Employee ID: " << empID << std::endl;
    }
};

int main() {
    // 创建Manager对象
    Manager manager("John Doe", 35, 1001, "IT");

    
    // 调用display和showEmployee函数显示信息
    manager.display();
    manager.showEmployee();

    return 0;
}
