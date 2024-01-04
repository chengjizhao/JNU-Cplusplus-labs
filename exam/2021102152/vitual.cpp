#include<iostream>
class Animal {
public:
    virtual void makeSound() {
        std::cout << "The animal makes a sound." << std::endl;
    }
};
class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "The dog barks." << std::endl;
    }
};