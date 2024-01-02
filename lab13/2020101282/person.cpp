#include <iostream>
#include <memory>
#include <string>

class Address;  // 前置声明

class Person {
public:
    Person(const std::string& name, int age) : name(name), age(age) {}

    void setAddress(std::shared_ptr<Address> address) {
        addressPtr = address;
    }

    void displayInfo() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }

private:
    std::string name;
    int age;
    std::shared_ptr<Address> addressPtr;
};

class Address {
public:
    Address(const std::string& city, const std::string& street) : city(city), street(street) {}

    void setPerson(std::weak_ptr<Person> person) {
        personWeakPtr = person;
    }

    void displayInfo() const {
        std::cout << "City: " << city << ", Street: " << street << std::endl;
    }

private:
    std::string city;
    std::string street;
    std::weak_ptr<Person> personWeakPtr;
};

int main() {
    // 创建 Address 实例
    auto address1 = std::make_shared<Address>("City1", "Street1");
    auto address2 = std::make_shared<Address>("City2", "Street2");

    // 创建 Person 实例，并设置地址
    auto person1 = std::make_shared<Person>("Person1", 25);
    auto person2 = std::make_shared<Person>("Person2", 30);

    person1->setAddress(address1);
    person2->setAddress(address2);

    // 设置 Address 实例的关联 Person
    address1->setPerson(person1);
    address2->setPerson(person2);

    // 输出信息
    std::cout << "Person1 Info:" << std::endl;
    person1->displayInfo();
    std::cout << "Person1 Address Info:" << std::endl;
    address1->displayInfo();

    std::cout << "\nPerson2 Info:" << std::endl;
    person2->displayInfo();
    std::cout << "Person2 Address Info:" << std::endl;
    address2->displayInfo();

    // 在程序结束时，观察对象的销毁顺序

    return 0;
}
