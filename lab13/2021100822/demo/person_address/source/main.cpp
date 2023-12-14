#include <iostream>
#include <memory>
#include "Person.h"
#include "Address.h"

int main() {
    std::shared_ptr<Person> person1 = std::make_shared<Person>("Alice", 25);
    std::shared_ptr<Address> address1 = std::make_shared<Address>("New York", "Broadway");

    person1->setAddress(address1);
    address1->addResident(person1);

    {
        std::shared_ptr<Person> person2 = std::make_shared<Person>("Bob", 30);
        std::shared_ptr<Address> address2 = std::make_shared<Address>("Los Angeles", "Hollywood");

        person2->setAddress(address2);
        address2->addResident(person2);

    } 

    return 0;
}