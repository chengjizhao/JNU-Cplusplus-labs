#include <iostream>

class MyClass {
private:
    void privateFunction() {
        std::cout << "Private Function called." << std::endl;
    }

public:
    void publicFunction() {
        std::cout << "Public Function called." << std::endl;
    }
};

int main() {
    MyClass obj;
    void (MyClass:: * functionPtr)() = &MyClass::privateFunction;
    return 0;
}