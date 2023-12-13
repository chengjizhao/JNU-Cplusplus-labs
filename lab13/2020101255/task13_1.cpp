#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Address;  // ǰ������ Address ��

class Person
{
    public:
        Person(const string& name, int age) : name(name), age(age) {}

        void setAddress(shared_ptr<Address> address)
        {
            this->address = address;
        }

        string getName() const
        {
            return name;
        }

    private:
        shared_ptr<Address> address;
        string name;
        int age;
};

class Address
{
    public:
        Address(const string& city, const string& street) : city(city), street(street) {}

        void setPerson(weak_ptr<Person> person)
        {
            this->person = person;
        }

        string getCity() const
        {
            return city;
        }

    private:
        weak_ptr<Person> person;
        string city;
        string street;
};

int main() {
    // ���� Person �� Address ʵ��
    shared_ptr<Person> person1 = make_shared<Person>("Alice", 25);
    shared_ptr<Person> person2 = make_shared<Person>("Bob", 30);
    shared_ptr<Address> address = make_shared<Address>("Shanghai", "Nanjing Road");

    // ���� Person �� Address ֮��Ĺ�ϵ
    person1->setAddress(address);
    address->setPerson(person2);

    // ��������Ϣ
    cout << "Person 1: " << person1->getName() << " - Address: " << address->getCity() << endl;
    cout << "Person 2: " << person2->getName() << " - Address: " << address->getCity() << endl;

    return 0;
}
