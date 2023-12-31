#include <iostream>
#include <memory>
using namespace std;

class Person;

class Address
{
public:
    weak_ptr<Person> person;
    Address(string city, string street) : city_(city), street_(street) {}
    ~Address()
    {
        cout << "Address������" << endl;
    }
    string city_;
    string street_;
};

class Person
{
public:
    shared_ptr<Address> address;
    Person(std::string name, int age) : name_(name), age_(age) {}
    ~Person()
    {
        cout << "Person������" << endl;
    }
    void display()
    {
        cout << "������" << name_ << endl;
        cout << "���䣺" << age_ << endl;
        cout << "��ס�ص�:" << address->city_ << "," << address->street_ << endl;
    }
    string name_;
    int age_;
};

int main()
{
    {
        shared_ptr<Address> addr1 = make_shared<Address>("Zhuhai", "Qianshan");
        shared_ptr<Person> person1 = make_shared<Person>("John Doe", 22);
        shared_ptr<Person> person2 = make_shared<Person>("Jane Smith", 30);
        person1->address = addr1;
        addr1->person = person1;
        person2->address = addr1;
        addr1->person = person1;
        person1->display();
        person2->display();
    }

    return 0;
}