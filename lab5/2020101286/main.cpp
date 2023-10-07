#include "person.h"
#include <iostream>
using namespace std;

int main() 
{
    Person person1;

    Person person2("Mike", "1234567890", "2001-11-12", "Male", 175.0, 64.0);

    Person person3;
    person3.inputFromTerminal();

    std::cout << "Person 1:\n";
    std::cout << "Name: " << person1.getName() << std::endl;
    std::cout << "ID: " << person1.getID() << std::endl;
    std::cout << "Date of Birth: " << person1.getDOB() << std::endl;
    std::cout << "Gender: " << person1.getGender() << std::endl;
    std::cout << "Height: " << person1.getHeight() << std::endl;
    std::cout << "Weight: " << person1.getWeight() << std::endl;

    std::cout << "\nPerson 2:\n";
    std::cout << "Name: " << person2.getName() << std::endl;
    std::cout << "ID: " << person2.getID() << std::endl;
    std::cout << "Date of Birth: " << person2.getDOB() << std::endl;
    std::cout << "Gender: " << person2.getGender() << std::endl;
    std::cout << "Height: " << person2.getHeight() << std::endl;
    std::cout << "Weight: " << person2.getWeight() << std::endl;

    std::cout << "\nPerson 3:\n";
    std::cout << "Name: " << person3.getName() << std::endl;
    std::cout << "ID: " << person3.getID() << std::endl;
    std::cout << "Date of Birth: " << person3.getDOB() << std::endl;
    std::cout << "Gender: " << person3.getGender() << std::endl;
    std::cout << "Height: " << person3.getHeight() << std::endl;
    std::cout << "Weight: " << person3.getWeight() << std::endl;

    cout << "\nperson1有"<< sizeof(person1) <<"字节" <<endl;
    cout << "person2有"<<sizeof(person2) <<"字节"<< endl;
    cout << "person3有"<<sizeof(person3) <<"字节\n"<< endl;

    return 0;
}