#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <memory>

using namespace std;

class Address;
class Person
{
public:
    shared_ptr<Address> address_sharedPtr;
    ~Person()
    {
        cout << "Address's UseCount before expire: " <<address_sharedPtr.use_count() << endl;
    }

    const char* name;
    int age;
};

class Address
{
public:
    weak_ptr<Person> person_weakPtr;
    ~Address()
    {
        cout << "Person's UseCount before expire: " <<person_weakPtr.use_count() << endl;
    }

    const char* city;
    const char* location;
};


#endif
