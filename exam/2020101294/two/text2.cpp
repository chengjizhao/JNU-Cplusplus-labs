#include <iostream>

// ����
class BaseClass {
public:
    virtual void virtualFunction() const {
        std::cout << "BaseClass virtualFunction" << std::endl;
    }
};

// ������
class DerivedClass : public BaseClass {
public:
    void virtualFunction() const override {
        std::cout << "DerivedClass virtualFunction" << std::endl;
    }
};

int main() {
    BaseClass* obj = new DerivedClass();  // ʹ�û���ָ��ָ�����������
    obj->virtualFunction();  // �����麯��������ʱ������DerivedClass��ʵ��

    delete obj;
    // �ȴ��û����룬��ֹ���������˳�
    std::cout << "Press Enter to exit." << std::endl;
    std::cin.get();
    return 0;
}