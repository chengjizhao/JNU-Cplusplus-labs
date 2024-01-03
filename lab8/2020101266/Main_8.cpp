#include <iostream>  
#include <vector>  

//�麯����C++��ʵ�ֶ�̬��һ�ֻ��ƣ���ʵ���������麯����vtable����ÿ�������麯�����඼����һ���麯�����ñ���������������麯���ĵ�ַ��ÿ��������麯����ָ�루vptr������ָ������������麯����
//��һ����̳�����һ�������麯������ʱ������Ĺ��캯���Ḻ���ʼ����vptr��ʹ��ָ���Լ����麯����

class Base {
public:
    virtual void func() { std::cout << "Base::func()" << std::endl; }
};

class Derived : public Base {
public:
    void func() override { std::cout << "Derived::func()" << std::endl; }
};

int main() {
    std::vector<Base*> objects;
    for (int i = 0; i < 10; ++i) {
        objects.push_back(new Derived());
    }

    for (auto obj : objects) {
        obj->func(); // ��� "Derived::func()" 10��  
    }

    for (auto obj : objects) {
        std::cout << "vptr address: " << &obj->vptr() << std::endl; // ���ÿ�������vptr��ַ  
    }

    for (auto obj : objects) {
        delete obj; // �ͷ��ڴ�  
    }
    objects.clear();

    return 0;
}