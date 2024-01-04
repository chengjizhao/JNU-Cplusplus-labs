#include <iostream>
#include <string>

using namespace std;

class Person
{
    private:
        string name;
        int age;
    public:
        Person(const string& n, int a) : name(n), age(a) {}
        void display() const { cout << "Name: " << name << ", Age: " << age << endl; }
};

class Employee
{
    private:
        int empID;
    public:
        Employee(int id) : empID(id) {}
        void showEmployee() const { cout << "Employee ID: " << empID << endl; }
};

class Manager : public Person, public Employee
{
    private:
        string department;
    public:
        Manager(const string& n, int a, int id, const string& d) : Person(n, a), Employee(id), department(d) {}
        void display() const
        {
            Person::display();
            cout << "Department: " << department << endl;
        }
        void showEmployee() const
        {
            Employee::showEmployee();
            cout << "Department: " << department << endl;
        }
};

int main()
{
    Manager manager("John Doe", 35, 12345, "Sales");
    manager.display();
    manager.showEmployee();
    
    return 0;
}
