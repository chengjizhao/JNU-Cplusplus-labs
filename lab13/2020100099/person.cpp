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
    std::string street;
    std::string city;
    std::weak_ptr<Person> person;

    Address(const std::string& street, const std::string& city) : street(street), city(city) {
        std::cout << "Creating Address in " << city << std::endl;
    }

    ~Address() {
        std::cout << "Destroying Address in " << city << std::endl;
    }
};

int main() {

    std::shared_ptr<Person> person1 = std::make_shared<Person>("A", 25);
    std::shared_ptr<Person> person2 = std::make_shared<Person>("B", 30);
    std::shared_ptr<Address> address1 = std::make_shared<Address>("1 Street", "Zhuhai");
    std::shared_ptr<Address> address2 = std::make_shared<Address>("2 Street", "Guangzhou");

    person1->address = address1;
    person2->address = address2;
    address1->person = person1;
    address2->person = person2;

    std::cout << person1->name << "'s address: " << person1->address->city << ", " << person1->address->street << std::endl;
    std::cout << person2->name << "'s address: " << person2->address->city << ", " << person2->address->street << std::endl;

    person1.reset(); 
    person2.reset(); 

    return 0;
}