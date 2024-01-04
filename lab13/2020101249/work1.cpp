#include <iostream>
#include <memory>
#include <string>

class Address; // Forward declaration

class Person {
public:
    Person(const std::string& name, int age) : name(name), age(age) {}

    void setAddress(std::shared_ptr<Address> addr) {
        address = addr;
    }

    void displayInfo() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
        if (address) {
            std::cout << "Address: " << address->getFullAddress() << std::endl;
        } else {
            std::cout << "No address specified." << std::endl;
        }
    }

private:
    std::string name;
    int age;
    std::shared_ptr<Address> address;
};

class Address {
public:
    Address(const std::string& city, const std::string& street) : city(city), street(street) {}

    void setPerson(std::shared_ptr<Person> person) {
        personPtr = person;
    }

    std::string getFullAddress() const {
        return city + ", " + street;
    }

    ~Address() {
        std::cout << "Address destroyed: " << getFullAddress() << std::endl;
    }

private:
    std::string city;
    std::string street;
    std::weak_ptr<Person> personPtr;
};

int main() {
    // Create instances using shared_ptr
    auto person1 = std::make_shared<Person>("John Doe", 30);
    auto person2 = std::make_shared<Person>("Jane Smith", 25);

    auto address1 = std::make_shared<Address>("CityA", "StreetA");
    auto address2 = std::make_shared<Address>("CityB", "StreetB");

    // Set relationships
    person1->setAddress(address1);
    person2->setAddress(address2);

    address1->setPerson(person1);
    address2->setPerson(person2);

    // Display information
    std::cout << "Person 1:" << std::endl;
    person1->displayInfo();
    std::cout << std::endl;

    std::cout << "Person 2:" << std::endl;
    person2->displayInfo();
    std::cout << std::endl;

    // Note: The destruction order may vary depending on the implementation
    // and the order in which objects go out of scope.

    return 0;
}