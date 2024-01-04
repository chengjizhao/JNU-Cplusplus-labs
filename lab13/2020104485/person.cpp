#include <iostream>  
#include <memory>  
#include <string>  
  
class Address;  
  
class Person {  
public:  
    Person(const std::string& name, int age, std::shared_ptr<Address> address)  
        : name_(name), age_(age), address_(address) {  
        if (address_) {  
            address_->AddResident(this);  
        }  
    }  
  
    ~Person() {  
        if (address_) {  
            address_->RemoveResident(this);  
        }  
    }  
  
    void DisplayInfo() const {  
        std::cout << "Person: " << name_ << ", Age: " << age_ << std::endl;  
        if (address_) {  
            address_->DisplayInfo();  
        } else {  
            std::cout << "No address." << std::endl;  
        }  
    }  
  
private:  
    std::string name_;  
    int age_;  
    std::shared_ptr<Address> address_;  
};  
  
class Address {  
public:  
    Address(const std::string& city, const std::string& street)  
        : city_(city), street_(street) {}  
  
    void AddResident(const Person* person) {  
        residents_.push_back(person);  
    }  
  
    void RemoveResident(const Person* person) {  
        for (auto it = residents_.begin(); it != residents_.end(); ++it) {  
            if (*it == person) {  
                residents_.erase(it);  
                break;  
            }  
        }  
    }  
  
    void DisplayInfo() const {  
        std::cout << "  Address: " << city_ << ", " << street_ << std::endl;  
        for (const auto& resident : residents_) {  
            resident->DisplayInfo();  
        }  
    }  
  
private:  
    std::string city_;  
    std::string street_;  
    std::vector<std::weak_ptr<const Person>> residents_;  
};  
  
int main() {  
    std::cout << "Creating objects..." << std::endl;  
    {  
        std::shared_ptr<Address> address1 = std::make_shared<Address>("CityA", "Street1");  
        std::shared_ptr<Address> address2 = std::make_shared<Address>("CityB", "Street2");  
        std::shared_ptr<Person> person1 = std::make_shared<Person>("Alice", 30, address1);  
        std::shared_ptr<Person> person2 = std::make_shared<Person>("Bob", 40, address1);  
        std::shared_ptr<Person> person3 = std::make_shared<Person>("Charlie", 35, address2);  
        person1->DisplayInfo();  
        person2->DisplayInfo();  
        person3->DisplayInfo();  
    }  
    std::cout << "Objects destroyed." << std::endl;  
    return 0;  
}
