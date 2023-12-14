#include <iostream>
#include <memory>
#include <string>

class Address;

class Person {
public:
    std::string name;
    int age;
    std::shared_ptr<Address> address;

    Person(const std::string& name, int age) : name(name), age(age) {
        std::cout << "Creating Person: " << name << std::endl;
    }

    ~Person() {
        std::cout << "Destroying Person: " << name << std::endl;
    }
};

class Address {
public:
    std::string city;
    std::string street;
    std::weak_ptr<Person> person;

    Address(const std::string& city, const std::string& street) : city(city), street(street) {
        std::cout << "Creating Address in " << city << std::endl;
    }

    ~Address() {
        std::cout << "Destroying Address in " << city << std::endl;
    }
};

int main() {
    // Creating Person and Address instances
    std::shared_ptr<Person> person1 = std::make_shared<Person>("Ali", 22);
    std::shared_ptr<Person> person2 = std::make_shared<Person>("TenX", 33);
    std::shared_ptr<Address> address1 = std::make_shared<Address>("zhongguoxianggang", "1997");
    std::shared_ptr<Address> address2 = std::make_shared<Address>("zhongguoaomen", "1999");

    // Establishing relationships using smart pointers
    person1->address = address1;
    person2->address = address2;
    address1->person = person1;
    address2->person = person2;

    // Outputting information
    std::cout << "Person 1's address: " << person1->address->city << ", " << person1->address->street << std::endl;
    std::cout << "Person 2's address: " << person2->address->city << ", " << person2->address->street << std::endl;

    // Observing object destruction order
    person1.reset(); // Resetting the shared_ptr to Person
    address1.reset(); // Resetting the shared_ptr to Address

    return 0;
}