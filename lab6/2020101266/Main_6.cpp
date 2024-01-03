#include <iostream>  

class MyClass {
private:
    int privateVar = 10;
    void privateFunc() {
        std::cout << "Private function called." << std::endl;
    }

public:
    friend void callPrivateFunc(MyClass& obj); // 声明为友元函数  
};

void callPrivateFunc(MyClass& obj) {
    obj.privateFunc(); // 访问私有成员函数  
}

int main() {
    MyClass obj;
    callPrivateFunc(obj); // 调用友元函数，间接调用私有成员函数  
    return 0;
}