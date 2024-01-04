#include <iostream>

class Animal 
{
    public:
    virtual void speak() const 
    { 
        std::cout << "Animal speaks!" << std::endl;
    }
};

class Dog:public Animal
{
    public:
    void speak() const override
    {
        std::cout<<"woof!"<<std::endl;

    }
};

class Cat:public Animal
{
    public:
    void speak() const override
    {
        std::cout<<"Meow!!"<<std::endl;
        
    }
};

int main() 
{
    Animal* animals[2];
    animals[0] = new Dog();
    animals[1] = new Cat();

    for (int i = 0; i < 2; ++i) 
    {
        animals[i]->speak();
    }

    return 0;
}