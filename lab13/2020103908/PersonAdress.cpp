#include <iostream>
#include <memory>
#include <string>

class Address;

class Person {
public:
    Person(const std::string& name, int age) : name(name), age(age) {}

    void setAddress(std::shared_ptr<Address> addr) {
        address = addr;
    }

    void displayInfo() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }

    ~Person() {
        std::cout << "Person " << name << " is being destroyed." << std::endl;
    }

private:
    std::string name;
    int age;
    std::shared_ptr<Address> address;
};

class Address {
public:
    Address(const std::string& city, const std::string& street) : city(city), street(street) {}

    void setPerson(std::weak_ptr<Person> person) {
        owner = person;
    }

    void displayInfo() const {
        std::cout << "City: " << city << ", Street: " << street << std::endl;
    }

    ~Address() {
        std::cout << "Address in " << city << " is being destroyed." << std::endl;
    }

private:
    std::string city;
    std::string street;
    std::weak_ptr<Person> owner;
};

int main() {
    // Creating instances using smart pointers
    std::shared_ptr<Person> person1 = std::make_shared<Person>("Alice", 30);
    std::shared_ptr<Person> person2 = std::make_shared<Person>("Bob", 25);

    std::shared_ptr<Address> address1 = std::make_shared<Address>("CityA", "StreetA");
    std::shared_ptr<Address> address2 = std::make_shared<Address>("CityB", "StreetB");

    // Establishing relationships between Person and Address
    person1->setAddress(address1);
    person2->setAddress(address2);

    address1->setPerson(person1);
    address2->setPerson(person2);

    // Displaying information
    std::cout << "Person 1 Info:" << std::endl;
    person1->displayInfo();
    std::cout << "Person 1's Address Info:" << std::endl;
    address1->displayInfo();

    std::cout << "\nPerson 2 Info:" << std::endl;
    person2->displayInfo();
    std::cout << "Person 2's Address Info:" << std::endl;
    address2->displayInfo();

    // Observing destruction sequence
    // No need to manually delete objects, smart pointers handle memory deallocation automatically

    return 0;
}
