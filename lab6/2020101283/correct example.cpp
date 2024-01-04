#include <iostream>

class MyClass {
private:
    void privateFunction() {
        std::cout << "Private function called." << std::endl;
    }

public:
    void publicFunction() {
        std::cout << "Public function called." << std::endl;
        privateFunction();  // 在公有成员函数中调用私有成员函数
    }

    friend void friendFunction(MyClass& obj);  // 友元函数声明
};

void friendFunction(MyClass& obj) {
    std::cout << "Friend function called." << std::endl;
    obj.privateFunction();  // 在友元函数中调用私有成员函数
}

int main() {
    MyClass obj;
    obj.publicFunction();       // 通过公有成员函数调用私有成员函数
    friendFunction(obj);        // 通过友元函数调用私有成员函数
    return 0;
}
