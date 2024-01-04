#include <iostream>
#include <memory>
using namespace std;

class Address;
class Person {
public:
    Person(const std::string& name, int age) : name_(name), age_(age) {}

    std::string GetName() const { return name_; }
    int GetAge() const { return age_; }
    
    shared_ptr<Address> address;
    ~Person() {
        std::cout << "Destroying Person: " << name_ << std::endl;
    }
private:
    std::string name_;
    int age_;
};

class Address {
public:
    Address(const std::string& city, const std::string& street)
        : city_(city), street_(street) {}

    std::string GetCity() const { return city_; }
    std::string GetStreet() const { return street_; }

    std::weak_ptr<Person> person;
    ~Address() {
        std::cout << "Destroying Address: " << city_ << std::endl;
    }
private:
    std::string city_;
    std::string street_;
};

int main() {
    // Create Person instances
    shared_ptr<Person> person1 = make_shared<Person>("Alice", 30);
    shared_ptr<Person> person2 = make_shared<Person>("Bob", 25);
    shared_ptr<Person> person3 = make_shared<Person>("Charlie", 22);
    // Create Address instances
    shared_ptr<Address> address1 = make_shared<Address>("New York", "Main St");
    shared_ptr<Address> address2 = make_shared<Address>("Los Angeles", "Sunset Blvd");

    // Establish relationships between Person and Address
    person1->address = address1;
    person2->address = address1;    

    // 输出
    cout << "Person 1: " << person1->GetName() << "," << person1->GetAge() << endl
    << "Address: " << person1->address->GetCity() << "," << person1->address->GetStreet() << endl;
    cout << "Person 2: " << person2->GetName() << "," << person2->GetAge() << endl
    << "Address: " << person2->address->GetCity() << "," << person2->address->GetStreet() << endl;
    //没有建立关系的person3和address2
    cout << "Person 3: " << person3->GetName() << "," << person3->GetAge() << endl
    << "Address: " << address2->GetCity() << "," << address2->GetStreet() << endl;

    return 0;
}
//person3->address,Address出现段错误
//address2->person,运算符 -> 或 ->* 应用于 "std::weak_ptr<Person>" 而不是指针类型