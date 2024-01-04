#include <iostream>  
#include <memory>  
  
class Person;  // 前置声明  

class Address {  
public:  
    Address(const std::string& street, const std::string& city, const std::string& state)  
        : street(street), city(city), state(state){}  
    void setPerson(std::shared_ptr<Person> person) 
    {  
        personRef = person;  // 设置 weak_ptr，避免循环引用  
    }  
  
    void print() const 
    {  
        std::cout << "Street: " << street << ", City: " << city << ", State: " << state << std::endl;  
    }   
    std::string street;  
    std::string city;  
    std::string state;  
    std::weak_ptr<Person> personRef;  // 使用 weak_ptr 避免循环引用  
};  

class Person {  
public:  
    Person(const std::string& name, std::shared_ptr<Address>address)  
        : name_(name), address_(address) {}  
    void print()
    {  
        std::cout << "Name: " << name_ << ", Address: " << address_->state<< ", " <<address_->city<< ", " << std::endl;  
    } 
    std::string name_;  
    std::shared_ptr<Address>address_;  // 使用 shared_ptr 管理地址对象  
};  
  

  
int main() {  
    // 创建 Address 对象并使用 unique_ptr 管理其生命周期  
    std::shared_ptr<Address> address_ptr = std::make_shared<Address>("123 Main St", "Springfield", "IL");  
    address_ptr->print();// 输出地址信息  
    // 创建 Person 对象并使用 shared_ptr 管理其生命周期，同时使用 shared_ptr 管理地址对象
    std::shared_ptr<Person> person1 = std::make_shared<Person>("John Doe", address_ptr);  
    // 创建另一个 Person 对象并使用 shared_ptr 管理其生命周期，同时使用 shared_ptr 管理地址对象  
    std::shared_ptr<Person> person2 = std::make_shared<Person>("Jane Doe", address_ptr); 
    person1->print();  // 输出个人信息和地址信息  
    person2->print();  // 输出个人信息和地址信息  
    // 当 person1 和 person2 的生命周期结束时，它们的析构函数会自动释放资源，因为使用了 shared_ptr 管理对象。  
    // 同时，当 address 的生命周期结束时（由于 unique_ptr 的存在），其析构函数也会自动释放资源。  
    return 0;  
}
