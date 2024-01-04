#include <iostream>  
#include <memory>  
#include <string>  
#include<vector>
  
class Address;  
  
class Person 
{  
public:  
    Person(const std::string& name, int age, const std::shared_ptr<Address>& address)  
        : name_(name), age_(age), address_(address) {}  
  
    void PrintInfo() const;  
  
private:  
    std::string name_;  
    int age_;  
    std::shared_ptr<Address> address_; // Person拥有一个shared_ptr指向其地址  
};  
  
class Address {  
public:  
    Address(const std::string& city, const std::string& street)  
        : city_(city), street_(street) {}  
  
    void AddResident(const std::weak_ptr<Person>& resident) 
    {  
        residents_.push_back(resident);  
    }  
  
    void PrintInfo() const;  
    void PrintResidents() const;  
  
private:  
    std::string city_;  
    std::string street_;  
    std::vector<std::weak_ptr<Person>> residents_; // Address使用weak_ptr来观察Person，不持有所有权  
};  
  
void Person::PrintInfo() const 
{  
    std::cout << "Person: " << name_ << ", Age: " << age_ << std::endl;  
    if (address_) {  
        address_->PrintInfo();  
    } else {  
        std::cout << "No address." << std::endl;  
    }  
}  
  
void Address::PrintInfo() const 
{  
    std::cout << "  Address: " << city_ << ", " << street_ << std::endl;  
}  
  
void Address::PrintResidents() const 
{  
    std::cout << "  Residents:" << std::endl;  
    for (const auto& resident : residents_) 
    {  
        if (auto locked = resident.lock()) 
        {  
            locked->PrintInfo(); // 仅当Person还存在时才打印信息  
        } 
        else 
        {  
            std::cout << "(Resident no longer exists)" << std::endl;  
        }  
    }  
}  
  
int main() 
{
    auto address1 = std::make_shared<Address>("CityA", "Street1");  
    auto address2 = std::make_shared<Address>("CityB", "Street2");  
    std::shared_ptr<Person> person1 = std::make_shared<Person>("Alice", 30, address1);  
    std::shared_ptr<Person> person2 = std::make_shared<Person>("Bob", 40, address1);  
    std::shared_ptr<Person> person3 = std::make_shared<Person>("Charlie", 25, address2);  
    address1->AddResident(person1); 
    address1->AddResident(person2); 
    address2->AddResident(person3);// 打印人员和地址信息，观察销毁顺序（在程序结束时观察）  
    person1->PrintInfo(); 
    person2->PrintInfo(); 
    person3->PrintInfo(); 
    std::cout << "Printing residents of address1:" << std::endl; // This will print Alice and Bob's info again. It's just for demonstration purposes. In a real-world scenario, you wouldn't do this because it's redundant. You would just query the residents when needed.  
    address1->PrintResidents();
}