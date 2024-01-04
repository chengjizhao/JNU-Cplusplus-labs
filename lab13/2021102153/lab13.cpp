#include<iostream>
#include<memory>
using namespace std;
class Person;//声明

class Address
{
public:
    std::weak_ptr<Person> person;
    Address(std::string city, std::string street) : city(city), street(street) {}
    std::string city;
    std::string street;
    ~Address()
    {
        std::cout << "Address" << std::endl;
    }
};

class Person
{
public:
    std::shared_ptr<Address> address;
    Person(std::string name, int age) : name_(name), age_(age) {}
    void display()
    {
        std::cout << "姓名：" << name_<< std::endl
                  << "年龄：" << age_<< std::endl
                  << "地点:" << address->city << "," << address->street << std::endl;
    }
    ~Person()
    {
        std::cout << "Person" << std::endl;
    }
    std::string name_;
    int age_;
};

int main()
{
    {
        std::shared_ptr<Address> addr1 = std::make_shared<Address>("sz", "cd");
        std::shared_ptr<Address> addr2 = std::make_shared<Address>("ts", "td");
        std::shared_ptr<Person> person1 = std::make_shared<Person>("yyc", 19);
        std::shared_ptr<Person> person2 = std::make_shared<Person>("ac", 30);
        person1->address = addr1;
        addr1->person = person1;
        person2->address = addr2;
        addr2->person = person2;
        person1->display();
        person2->display();
    }

    return 0;
}