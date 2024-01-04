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
    // ʹ��shared_ptr����Address����
    auto address1 = std::make_shared<Address>("City1", "Street1");
    auto address2 = std::make_shared<Address>("City2", "Street2");

    // ʹ��shared_ptr����Person���󣬲�������ϵ
    auto person1 = std::make_shared<Person>("Person1", 25, address1);
    auto person2 = std::make_shared<Person>("Person2", 30, address2);

    // ʹ��Address�Ĺ�����������Address��Person�ķ����ϵ
    address1->setPerson(person1);
    address2->setPerson(person2);

    // ��ʾ��Ϣ
    std::cout << "Program execution completed." << std::endl;

    // ����ָ����Զ���������

    return 0;
}