#include <iostream>

// �������
class Shape {
public:
    virtual void draw() const = 0; // ���麯��
};

// ������
class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a circle" << std::endl;
    }
};

int main() {
    // �޷�ʵ����������Shape
    // Shape s;  // ��ᵼ�±������

    Circle c;
    c.draw(); // ����Circle���draw����

    return 0;
}