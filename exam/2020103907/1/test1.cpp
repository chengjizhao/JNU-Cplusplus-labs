#include <iostream>
using namespace std;

class Animal {
public:
    virtual void speak() {
        cout << "Animal speaks" << endl;
    }

    virtual ~Animal() {}
};

class Dog : public Animal {
public:
    void speak() override {
        cout << "Woof!" << endl;
    }
};

class Cat : public Animal {
public:
    void speak() override {
        cout << "Meow!" << endl;
    }
};

int main() {
    Animal* animals[2];
    Dog myDog;
    Cat myCat;

    animals[0] = &myDog;
    animals[1] = &myCat;

    for (int i = 0; i < 2; ++i) {
        animals[i]->speak();
    }

    return 0;
}




