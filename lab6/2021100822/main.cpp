#include <iostream>

class MyClass {
private:
    void privateFunction() {
        std::cout << "Private function called" << std::endl;
    }

public:
    void publicFunction() {
        privateFunction();
    }

    friend void friendFunction(MyClass& obj);
};

void friendFunction(MyClass& obj) {
    obj.privateFunction();
}

int main() {
    MyClass obj;
    obj.publicFunction();
    friendFunction(obj);
    return 0;
}
