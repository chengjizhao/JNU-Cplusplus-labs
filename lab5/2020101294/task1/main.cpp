#include <iostream>
#include "Person.h"

Person InitializePerson(const std::string& name, const std::string& id = "", const std::string& birthDate = "", char gender = ' ', double height = 0.0, double weight = 0.0) {
    Person person(name);
    person.SetID(id);
    person.SetBirthDate(birthDate);
    person.SetGender(gender);
    person.SetHeight(height);
    person.SetWeight(weight);
    return person;
}

int main() {
    Person person1 = InitializePerson("A");
    Person person2 = InitializePerson("B", "1234567890", "2000-01-01", 'M', 175.0, 70.0);
    Person person3 = InitializePerson("C", "0987654321");
     Person person4 = InitializePerson("D", 'M');
    Person person5 = InitializePerson("E", "", "", 'F', 160.0, 55.0);

    std::cout << "Person 1: Name - " << person1.GetName() << std::endl;
    std::cout << "Person 2: Name - " << person2.GetName() << ", ID - " << person2.GetID() << ", Birth Date - " << person2.GetBirthDate() << ", Gender - " << person2.GetGender() << ", Height - " << person2.GetHeight() << ", Weight - " << person2.GetWeight() << std::endl;
    std::cout << "Person 3: Name - " << person3.GetName() << ", ID - " << person3.GetID() << std::endl;
    std::cout << "Person 4: Name - " << person4.GetName() << ", Gender - " << person4.GetGender() << std::endl;
    std::cout << "Person 5: Name - " << person5.GetName() << ", Gender - " << person5.GetGender() << ", Height - " << person5.GetHeight() << ", Weight - " << person5.GetWeight() << std::endl;

    std::cout << "Size of person1: " << sizeof(person1) << " bytes" << std::endl;
    std::cout << "Size of person2: " << sizeof(person2) << " bytes" << std::endl;

    return 0;
}