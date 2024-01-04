#include <iostream>

class MyClass {
private:
    int privateData = 42;

public:
    void publicFunction() {
        std::cout << "Public Function: " << privateData << std::endl;
    }
};

int main() {
    MyClass obj;

    // ʹ�ú���ָ����ù��г�Ա����
    void (MyClass::*funcPtr)() = &MyClass::publicFunction;
    (obj.*funcPtr)();

    return 0;
}