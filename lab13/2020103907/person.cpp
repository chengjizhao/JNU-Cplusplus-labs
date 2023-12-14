#include <iostream>
#include <memory>
#include <string>

using namespace std;
class Address; // forward declaration

class Person {
public:
    shared_ptr<Address> address; // shared_ptr to Address
    string name;
    int age;

    Person(const string& name, int age) : name(name), age(age) {
        cout << "Creating Person: " << name << endl;
    }

    ~Person() {
        cout << "Destroying Person: " << name << endl;
    }
};

class Address {
public:
    weak_ptr<Person> person; // weak_ptr to Person
    string city;
    string street;

    Address(const string& city, const string& street) : city(city), street(street) {
        cout << "Creating Address: " << street << ", " << city << endl;
    }

    ~Address() {
        cout << "Destroying Address: " << street << ", " << city << endl;
    }
};

int main() {
    shared_ptr<Person> person1 = make_shared<Person>("A", 18);
    shared_ptr<Address> address1 = make_shared<Address>("City A", "Shanghai");

    person1->address = address1;
    address1->person = person1;

    shared_ptr<Person> person2 = make_shared<Person>("B", 20);
    unique_ptr<Address> address2 = make_unique<Address>("City B", "Beijing");

    person2->address = move(address2);
    person2->address->person = person2;

    cout << "Person 1: " << person1->name << ", Age: " << person1->age
              << ", Address: " << person1->address->street << ", " << person1->address->city << std::endl;

    cout << "Person 2: " << person2->name << ", Age: " << person2->age
              << ", Address: " << person2->address->street << ", " << person2->address->city << std::endl;

    return 0;
}
