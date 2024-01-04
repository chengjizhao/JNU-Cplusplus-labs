//
//  main.cpp
//  exam
//
//  Created by mac on 2024/1/4.
//

#include <iostream>
#include <string>

class Person {
private:
 std::string name;
 int age;

public:
 Person(const std::string& name, int age) : name(name), age(age) {}

 void display() const {
 std::cout << "Name: " << name << ", Age: " << age << std::endl;
 }
};

class Employee : public Person {
private:
 int empID;

public:
 Employee(const std::string& name, int age, int empID) : Person(name, age), empID(empID) {}

 void showEmployee() const {
 std::cout << "Employee ID: " << empID << std::endl;
 }
};

class Manager : public Employee {
private:
 std::string department;

public:
 Manager(const std::string& name, int age, int empID, const std::string& department)
 : Employee(name, age, empID), department(department) {}

 void display() const {
 Person::display();
 std::cout << "Department: " << department << std::endl;
 }

 void showEmployee() const {
 Employee::showEmployee();
 std::cout << "Department: " << department << std::endl;
 }
};

int main() {
 Manager manager("Allen",25,12345, "Digital");
 manager.display();
 manager.showEmployee();

 return 0;
}
