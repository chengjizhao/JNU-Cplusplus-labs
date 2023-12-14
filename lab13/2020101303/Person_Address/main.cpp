#include "Person.h"
#include <iostream>
#include <memory>
using namespace std;

inline void print_info(shared_ptr<Person> p, shared_ptr<Address> a)
{
    cout << "Name: " << p->get_Name() << endl;
    cout << "Age: " << p->get_Age() << endl;
    cout << "Address: " << a->get_City() << "  " << a->get_Street() << endl;
    cout << endl;
}

int main() {
    shared_ptr<Address> address1 = make_shared<Address>("City 1", "Street 1");
    shared_ptr<Address> address2 = make_shared<Address>("City 2", "Street 2");

    shared_ptr<Person> person1 = make_shared<Person>("Person1", 20);
    shared_ptr<Person> person2 = make_shared<Person>("Person2", 30);

    person1 -> set_Address(address1);
    person2 -> set_Address(address2);

    print_info(person1, address1);
    print_info(person2, address2);

    return 0;
}
