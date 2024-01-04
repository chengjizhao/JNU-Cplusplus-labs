#include <iostream>
#include <memory>

class Person;

class Address
{
public:
    std::weak_ptr<Person> person;
    Address(std::string city, std::string street) : city_(city), street_(street) {}
    ~Address()
    {
        std::cout << "Address已析构" << std::endl;
    }
    std::string city_;
    std::string street_;
};

class Person
{
public:
    std::shared_ptr<Address> address;
    Person(std::string name, int age) : name_(name), age_(age) {}
    ~Person()
    {
        std::cout << "Person已析构" << std::endl;
    }
    void display()
    {
        std::cout << "姓名：" << name_ << std::endl
                  << "年龄：" << age_ << std::endl
                  << "居住地点:" << address->city_ << "," << address->street_ << std::endl;
    }
    std::string name_;
    int age_;
};

int main()
{
    {
        // 创建一个地址对象
        std::shared_ptr<Address> addr1 = std::make_shared<Address>("Zhuhai", "Qianshan");
        // 创建两个人
        std::shared_ptr<Person> person1 = std::make_shared<Person>("John Doe", 22);
        std::shared_ptr<Person> person2 = std::make_shared<Person>("Jane Smith", 30);
        person1->address = addr1;
        addr1->person = person1;
        person2->address = addr1;
        addr1->person = person1;
        person1->display();
        person2->display();
    }

    return 0;
}