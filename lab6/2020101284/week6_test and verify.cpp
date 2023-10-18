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

    // ���庯��ָ�벢���Ե���˽�г�Ա����
    void (MyClass:: * functionPtr)() = &MyClass::privateFunction;
    // ����ͨ������ָ�����˽�г�Ա����
    //(obj.*functionPtr)(); // ���д���ᵼ�±�������޷�����˽�г�Ա����

    return 0;
}