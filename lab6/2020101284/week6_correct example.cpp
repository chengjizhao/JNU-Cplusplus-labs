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
        privateFunction(); // �����ڹ��г�Ա������ֱ�ӵ���˽�г�Ա����
    }
};

void friendFunction(MyClass& obj) {
    std::cout << "Friend Function called." << std::endl;
    obj.privateFunction(); // ��Ԫ��������ֱ�ӷ���˽�г�Ա����
}

int main() {
    MyClass obj;
    obj.publicFunction(); // ͨ�����г�Ա��������˽�г�Ա����
    friendFunction(obj); // ͨ����Ԫ��������˽�г�Ա����

    return 0;
}