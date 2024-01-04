#include <iostream>

// �ӿ� Resizable
class Resizable {
public:
    virtual void resize(int factor) = 0;  // ���麯��
};

// ������� Drawable
class Drawable {
public:
    virtual void draw() const = 0;  // ���麯��
};

// ���� Circle���̳� Drawable �� Resizable �ӿ�
class Circle : public Drawable, public Resizable {
public:
    void draw() const override {
        std::cout << "Drawing a circle." << std::endl;
    }

    void resize(int factor) override {
        std::cout << "Resizing the circle by a factor of " << factor << "." << std::endl;
    }
};

// ���� Square���̳� Drawable �� Resizable �ӿ�
class Square : public Drawable, public Resizable {
public:
    void draw() const override {
        std::cout << "Drawing a square." << std::endl;
    }

    void resize(int factor) override {
        std::cout << "Resizing the square by a factor of " << factor << "." << std::endl;
    }
};

int main() {
    // ���� Drawable ָ�����飬����һ�� Circle ��һ�� Square ����
    Drawable* shapes[2];
    Circle circle;
    Square square;
    shapes[0] = &circle;
    shapes[1] = &square;

    // ͨ��ָ����� draw ����
    for (int i = 0; i < 2; ++i) {
        shapes[i]->draw();
    }

    // ͨ��ָ����� resize ����
    for (int i = 0; i < 2; ++i) {
        Resizable* resizableShape = dynamic_cast<Resizable*>(shapes[i]);  // ����ת��Ϊ Resizable
        if (resizableShape) {
            resizableShape->resize(2);
        }
    }
    // �ȴ��û����룬��ֹ���������˳�
    std::cout << "Press Enter to exit." << std::endl;
    std::cin.get();
    return 0;
}