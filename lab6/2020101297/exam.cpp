#include <iostream>

class MyClass {
private:
    void privateFunction() {
        std::cout << "Private Function called." << std::endl;
    }

    friend void friendFunction(MyClass& obj);

public:
    void publicFunction() {
        std::cout << "Public Function called." << std::endl;
        privateFunction();
    }
};

void friendFunction(MyClass& obj) {
    std::cout << "Friend Function called." << std::endl;
    obj.privateFunction();
}

int main() {
    MyClass obj;
    obj.publicFunction();
    friendFunction(obj);

    return 0;
}