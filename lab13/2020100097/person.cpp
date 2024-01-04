#include <iostream>  
#include <memory>  
  
class Address {  
public:  
    Address(const std::string& city, const std::string& street) : city_(city), street_(street) {}  
    void print() const {  
        std::cout << "Address: " << city_ << ", " << street_ << std::endl;  
    }  
private:  
    std::string city_;  
    std::string street_;  
};  
  
class Person {  
public:  
    Person(const std::string& name, int age) : name_(name), age_(age) {}  
    void setAddress(std::shared_ptr<Address> address) {  
        address_ = address;  
    }  
    void print() const {  
        std::cout << "Person: " << name_ << ", " << age_ << ", Address: ";  
        if (address_) {  
            address_->print();  
        } else {  
            std::cout << "Unknown" << std::endl;  
        }  
    }  
private:  
    std::string name_;  
    int age_;  
    std::shared_ptr<Address> address_;  
};  
  
int main() {    
    std::shared_ptr<Person> person1 = std::make_shared<Person>("Alice", 25);  
    std::shared_ptr<Person> person2 = std::make_shared<Person>("Bob", 30);  
    std::shared_ptr<Address> address = std::make_shared<Address>("New York", "5th Avenue");  
    person1->setAddress(address);   
    person2->setAddress(address); 
    address->print(); 
    person1->print(); 
    person2->print();
    return 0; 
}