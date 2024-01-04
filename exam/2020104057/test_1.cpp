#include <iostream>

using namespace std;

// 定义基类 Animal
class Animal {
public:
  virtual void speak() = 0;
};

// 派生类 Dog
class Dog : public Animal {
public:
  void speak() override {
    cout << "Woof!" << endl;
  }
};

// 派生类 Cat
class Cat : public Animal {
public:
  void speak() override {
    cout << "Meow!" << endl;
  }
};

//main函数
int main() {
  Animal *animals[2];
  animals[0] = new Dog();
  animals[1] = new Cat();

  for (int i = 0; i < 2; i++) {
    animals[i]->speak();
  }

  return 0;
}

