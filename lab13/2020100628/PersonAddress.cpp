#include <iostream>
#include <string>
#include <memory>

class Address;  // 前置声明

class Person {
public:
    Person(const std::string& name, int age) : name(name), age(age) {
        std::cout << "Person: " << name << " constructed." << std::endl;
    }

    ~Person() {
        std::cout << "Person: " << name << " destructed." << std::endl;
    }

    void setAddress(std::shared_ptr<Address> address) {
        this->address = address;
    }

private:
    std::string name;
    int age;
    std::shared_ptr<Address> address;
};

class Address {
public:
    Address(const std::string& city, const std::string& street) : city(city), street(street) {
        std::cout << "Address: " << city << ", " << street << " constructed." << std::endl;
    }

    ~Address() {
        std::cout << "Address: " << city << ", " << street << " destructed." << std::endl;
    }

    void setPerson(std::weak_ptr<Person> person) {
        this->person = person;
    }

private:
    std::string city;
    std::string street;
    std::weak_ptr<Person> person;
};

int main() {
    // 创建Person和Address实例
    std::shared_ptr<Person> person1 = std::make_shared<Person>("Alice", 25);
    std::shared_ptr<Person> person2 = std::make_shared<Person>("Bob", 30);
    std::shared_ptr<Address> address1 = std::make_shared<Address>("City A", "Street X");
    std::shared_ptr<Address> address2 = std::make_shared<Address>("City B", "Street Y");

    // 建立Person和Address之间的关系
    person1->setAddress(address1);
    person2->setAddress(address2);
    address1->setPerson(person1);
    address2->setPerson(person2);

    // 输出Person和Address信息
    std::cout << "Person 1: " << person1->getName() << ", " << person1->getAge() << std::endl;
    std::cout << "Person 2: " << person2->getName() << ", " << person2->getAge() << std::endl;
    std::cout << "Address 1: " << address1->getCity() << ", " << address1->getStreet() << std::endl;
    std::cout << "Address 2: " << address2->getCity() << ", " << address2->getStreet() << std::endl;

    return 0;
}
