#include <iostream>
#include <string>
#include <memory>

class Address;  // 前向声明

class Person {
public:
    Person(const std::string& name, int age) : name(name), age(age) {}

    void setAddress(std::shared_ptr<Address> addr) {
        address = addr;
    }

    ~Person() {
        std::cout << name << " is destroyed." << std::endl;
    }

private:
    std::string name;
    int age;
    std::shared_ptr<Address> address;
};

class Address {
public:
    Address(const std::string& city, const std::string& street) : city(city), street(street) {}

    void setPerson(std::weak_ptr<Person> p) {
        person = p;
    }

    ~Address() {
        std::cout << "Address in " << city << " is destroyed." << std::endl;
    }

private:
    std::string city;
    std::string street;
    std::weak_ptr<Person> person;
};

int main() {
    // 创建Person和Address的实例
    std::shared_ptr<Person> person1 = std::make_shared<Person>("Alice", 25);
    std::shared_ptr<Person> person2 = std::make_shared<Person>("Bob", 30);
    std::shared_ptr<Address> address = std::make_shared<Address>("New York", "Broadway");

    // 建立关系
    person1->setAddress(address);
    person2->setAddress(address);
    address->setPerson(person1);

    // 输出当前的引用计数
    std::cout << "Person1 reference count: " << person1.use_count() << std::endl;
    std::cout << "Person2 reference count: " << person2.use_count() << std::endl;
    std::cout << "Address reference count: " << address.use_count() << std::endl;

    return 0;
}  // 结束时，person1、person2和address将被正确销毁
