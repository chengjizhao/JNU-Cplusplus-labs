#include <iostream>
#include <memory>
#include <string>

class Address;

class Person 
{
private:
    std::string name;
    int age;
public:
    std::shared_ptr<Address> address;

    Person(std::string n, int a) : name(n), age(a) 
    {
      std::cout << "Person " << name << " created" << std::endl;
    }

    ~Person() 
    {
      std::cout << "Person " << name << " destroyed" << std::endl;
    }
};

class Address {
private:
    std::string city;
    std::string street;
public:
    std::weak_ptr<Person> person;

    Address(std::string c, std::string s) : city(c), street(s) 
    {
      std::cout << "Address in " << city << " created" << std::endl;
    }

    ~Address() 
    {
      std::cout << "Address in " << city << " destroyed" << std::endl;
    }
};

int main() 
{
    std::shared_ptr<Person> person1 = std::make_shared<Person>("Alice", 25);
    std::shared_ptr<Address> address1 = std::make_shared<Address>("New York", "Broadway");
    person1->address = address1;
    address1->person = person1;
    
    // 创建临时对象
    {      
      std::unique_ptr<Person> person2 = std::make_unique<Person>("Bob", 30);
      std::unique_ptr<Address> address2 = std::make_unique<Address>("Los Angeles", "Hollywood");
    }

  std::cout << "Main function end" << std::endl;

  system("pause");
  return 0;
}
