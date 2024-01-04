#include <iostream>  
  
class Animal {  
public:  
    virtual void speak() {  
        std::cout << "Some sound from animal" << std::endl;  
    }  
};  
  
class Dog : public Animal {  
public:  
    void speak() override {  
        std::cout << "Woof!" << std::endl;  
    }  
};  
  
class Cat : public Animal {  
public:  
    void speak() override {  
        std::cout << "Meow!" << std::endl;  
    }  
};  
  
int main() {  
    Animal* animals[2];  
    animals[0] = new Dog();  
    animals[1] = new Cat();  
      
    for (int i = 0; i < 2; ++i) {  
        animals[i]->speak();  
    }  
      
    delete animals[0];  
    delete animals[1];  
    return 0;  
}