#include <iostream>  

class MyClass {
private:
    int privateVar = 10;
    void privateFunc() {
        std::cout << "Private function called." << std::endl;
    }

public:
    friend void callPrivateFunc(MyClass& obj); // ����Ϊ��Ԫ����  
};

void callPrivateFunc(MyClass& obj) {
    obj.privateFunc(); // ����˽�г�Ա����  
}

int main() {
    MyClass obj;
    callPrivateFunc(obj); // ������Ԫ��������ӵ���˽�г�Ա����  
    return 0;
}