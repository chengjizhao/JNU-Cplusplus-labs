#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void speak() = 0;
};

class Cat :public Animal
{
public:
    void speak()
    {
        cout << "Meow" << endl;
    } 

};

class Dog :public Animal
{
public:
    void speak()
    {
        cout << "Woof" << endl;
    } 

};
int main() {
    Animal* animals[2];
    animals[0] = new Dog();
    animals[1] = new Cat();

    for (int i = 0; i < 2; i++) {
        animals[i]->speak();
    }

    delete[] animals;
    system("pause");
    return 0;
}

