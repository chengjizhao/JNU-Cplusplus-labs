#include<iostream>
#include<memory>
#include<string>

using namespace std;

class Person;
class Address;

class Person
{
public:
    Person(string name_, int age_) :name(name_), age(age_) {}
    void display()const;
    shared_ptr<Address>address;
    ~Person()
    {
        cout << "Psrson is destoryed" << endl;
    }
private:
    string name;
    int age;
};

class Address
{
public:
    Address(string city_, string street_) :city(city_), street(street_) {}
    void display()const;
    ~Address() {
        cout << "Address is destoryed" << endl;
    }
    weak_ptr<Person>person;
private:
    string city;
    string street;
};

void Person::display() const
{
    cout << "name:" << name << " " << "age:" << age << endl;
    if (address) {
        address->display();
    }
    else {
        std::cout << "No address" << std::endl;
    };
};

void Address::display() const
{
    cout << "city:" << city << " " << "street:" << street << endl;
};

int main()
{
    shared_ptr<Person>pp1 = make_shared<Person>("Alice", 25);
    shared_ptr<Person>pp2 = make_shared<Person>("Bob", 24);
    shared_ptr<Address>ap1 = make_shared<Address>("NEW YORK", "123 MAIN STREET");
    pp1->address = ap1;
    pp2->address = ap1;
    ap1->person = pp1;
    pp1->display();
    pp2->display();
    ap1->display();
    cout << "pp1.use_count():" << pp1.use_count() << endl;
    cout << "pp2.use_count():" << pp2.use_count() << endl;
    cout << "ap1.use_count():" << ap1.use_count() << endl;
    return 0;
}