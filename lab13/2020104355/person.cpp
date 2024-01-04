#include <iostream>
#include <memory>
class Address;
class Person {
public:
    std::shared_ptr<Address> address;
    std::string name;
    int age;
    Person(const std::string& n, int a) : name(n), age(a) {}
    ~Person() {
        std::cout << "Person " << name << " is destroyed" << std::endl;
    }
};
class Address {
public:
    std::weak_ptr<Person> person;
    std::string city;
    std::string street;
    Address(const std::string& c, const std::string& s) : city(c), street(s) {}
    ~Address() {
        std::cout << "Address in " << city << " is destroyed" << std::endl;
    }
};
int main() {
    std::shared_ptr<Person> person1 = std::make_shared<Person>("Alice", 25);
    std::shared_ptr<Person> person2 = std::make_shared<Person>("Bob", 30);
    std::shared_ptr<Address> address = std::make_shared<Address>("New York", "Broadway");
    person1->address = address;
    person2->address = address;
    address->person = person1;
    std::cout << "Created Person: " << person1->name << std::endl;
    std::cout << "Created Person: " << person2->name << std::endl;
    std::cout << "Created Address in: " << address->city << std::endl;