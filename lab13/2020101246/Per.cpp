#include <iostream>
#include <memory>
#include <string>

class Address;

class Person {
public:
    Person(const std::string& name, int age) 
    {
        m_name = name ;
        m_age = age;
        std::cout << "Creating Person: " << name << std::endl;
    }
    ~Person() {
        std::cout << "Destroying Person: " << m_name << std::endl;
    }

    void setAddress(std::shared_ptr<Address> address) 
    {
        this->address = address;
    }

private:
    std::string m_name;
    int m_age;
    std::shared_ptr<Address> address;
};

class Address {
public:
    Address(const std::string& city, const std::string& street)
    {
        m_city = city ;
        m_street = street;
        std::cout << "Creating Address: " << m_street << ", " << m_city << std::endl;
    }
    ~Address() {
        std::cout << "Destroying Address: " << m_street << ", " << m_city << std::endl;
    }

    void setPerson(std::weak_ptr<Person> person) 
    {
        this->person = person;
    }

private:
    std::string m_city;
    std::string m_street;
    std::weak_ptr<Person> person;
};

int main() {
    // 创建 Address 实例
    std::shared_ptr<Address> address1(new Address("City A", "Street 1"));
    std::shared_ptr<Address> address2(new Address("City B", "Street 2"));

    // 创建 Person 实例，并设置地址
    std::shared_ptr<Person> person1(new Person("Person 1", 25));
    person1->setAddress(address1);

    std::shared_ptr<Person> person2(new Person("Person 2", 30));
    person2->setAddress(address2);

    // 设置地址和人的关系
    address1->setPerson(person1);
    address2->setPerson(person2);

    // 输出相关信息
    std::cout << "Program finished!" << std::endl;

    return 0;
}