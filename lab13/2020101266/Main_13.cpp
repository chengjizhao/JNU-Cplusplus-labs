#include <iostream>  
#include <memory>  
#include <string>  

class Address;

class Person {
public:
    Person(const std::string& name, int age, const std::shared_ptr<Address>& address)
        : name_(name), age_(age), address_(address) {}

    void PrintInfo() const;

    ~Person() {
        std::cout << "Person " << name_ << " is being destroyed." << std::endl;
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

    void PrintInfo() const;

    ~Address() {
        std::cout << "Address " << city_ << ", " << street_ << " is being destroyed." << std::endl;
    }

    void SetResident(const std::weak_ptr<Person>& person) { resident_ = person; }
    std::weak_ptr<Person> GetResident() const { return resident_; }

private:
    std::string city_;
    std::string street_;
    std::weak_ptr<Person> resident_;
};

void Person::PrintInfo() const {
    std::cout << "Person: " << name_ << ", Age: " << age_ << std::endl;
    if (address_) {
        address_->PrintInfo();
        auto resident = address_->GetResident();
        if (auto locked = resident.lock()) {
            std::cout << "This person shares the address with: " << locked->name_ << std::endl;
        }
        else {
            std::cout << "This person does not share the address with anyone else." << std::endl;
        }
    }
    else {
        std::cout << "This person does not have an address." << std::endl;
    }
}

void Address::PrintInfo() const {
    std::cout << "Address: " << city_ << ", " << street_ << std::endl;
    if (auto locked = resident_.lock()) {
        std::cout << "Resident: " << locked->name_ << std::endl;
    }
    else {
        std::cout << "No resident." << std::endl;
    }
}

int main() {
    auto addr1 = std::make_shared<Address>("City1", "Street1");
    auto person1 = std::make_unique<Person>("Alice", 30, addr1);
    addr1->SetResident(person1->get_deleter()(person1.release())); // Tricky way to get a raw pointer without actually deleting it. In practice, you should avoid this.  
    // Consider using a container or another design pattern to establish the relationship.  
    auto person2 = std::make_unique<Person>("Bob", 35, addr1);
    addr1->SetResident(person2->get_deleter()(person2.release())); // Same as above, this is not a good practice. Just for demonstration.  
    // In a real scenario, you would establish the relationship differently.  
    person1->PrintInfo(); // This will show that Alice shares the address with Bob (even though Bob was the last one to set the relationship).  
    // However, note that this behavior is undefined because we used a hacky way to establish the relationship.  
    person2 = nullptr;   // Bob is destroyed, but the address remains because Alice still has a reference to it.  
    person1 = nullptr;   // Alice is destroyed, and now the address has no references, so it's also destroyed.  
    // The destruction order is Bob, Alice, and then the address. But this is not guaranteed by the standard.  
    // The important point is that there are no memory leaks.  
    return 0;
}