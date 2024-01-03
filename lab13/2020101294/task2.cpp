#include <iostream>
#include <memory>
#include <string>

class Address;

class Person {
public:
    Person(const std::string& name, int age, std::shared_ptr<Address> address)
        : name(name), age(age), address(address) {
        std::cout << "Person " << name << " created." << std::endl;
    }

    ~Person() {
        std::cout << "Person " << name << " is being destroyed." << std::endl;
    }

private:
    std::string name;
    int age;
    std::shared_ptr<Address> address;

    friend class Address; // Allow Address to access private members
};

class Address {
public:
    Address(const std::string& city, const std::string& street)
        : city(city), street(street) {
        std::cout << "Address in " << city << " created." << std::endl;
    }

    ~Address() {
        std::cout << "Address in " << city << " is being destroyed." << std::endl;
    }

    void setPerson(std::shared_ptr<Person> p) {
        person = p;
    }

private:
    std::string city;
    std::string street;
    std::weak_ptr<Person> person;
};

int main() {
    // 使用shared_ptr创建Address对象
    auto address1 = std::make_shared<Address>("City1", "Street1");
    auto address2 = std::make_shared<Address>("City2", "Street2");

    // 使用shared_ptr创建Person对象，并建立关系
    auto person1 = std::make_shared<Person>("Person1", 25, address1);
    auto person2 = std::make_shared<Person>("Person2", 30, address2);

    // 使用Address的公共方法建立Address到Person的反向关系
    address1->setPerson(person1);
    address2->setPerson(person2);

    // 显示信息
    std::cout << "Program execution completed." << std::endl;

    // 智能指针会自动处理销毁

    return 0;
}