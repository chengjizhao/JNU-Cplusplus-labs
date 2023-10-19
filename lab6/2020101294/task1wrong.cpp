#include <iostream>

class MyClass {
private:
    void privateFunction() {
        std::cout << "Private Function" << std::endl;
    }

public:
    void callPrivateFunction() {
        privateFunction();
    }
};

int main() {
    MyClass obj;

    // ����ʹ�ú���ָ�����˽�г�Ա����
    void (MyClass::*funcPtr)() = &MyClass::privateFunction;
    // (obj.*funcPtr)(); // ��һ�н����±������

    return 0;
}