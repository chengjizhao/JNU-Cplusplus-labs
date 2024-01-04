#include <iostream>
#include <vector>

// ����ɻ��Ƴ������
class Drawable {
public:
    virtual void draw() const = 0; // ���麯��
    virtual void resize(int factor) = 0; // ���麯��
};

// ����ɵ�����С�ӿ�
class Resizable {
public:
    virtual void resize(int factor) = 0; // ���麯��
};

// �̳пɻ��Ƴ�������Բ��
class Circle : public Drawable, public Resizable {
public:
    void draw() const override {
        // ����Բ��
        std::cout << "Draw a circle" << std::endl;
    }

    void resize(int factor) override {
        // ����Բ�δ�С
        std::cout << "Resize the circle by factor " << factor << std::endl;
    }
};

// �̳пɻ��Ƴ���������������
class Square : public Drawable, public Resizable {
public:
    void draw() const override {
        // ����������
        std::cout << "Draw a square" << std::endl;
    }

    void resize(int factor) override {
        // ���������δ�С
        std::cout << "Resize the square by factor " << factor << std::endl;
    }
};

int main() {
    // ����Drawableָ������
    std::vector<Drawable*> shapes;
    Circle circle;
    Square square;
    shapes.push_back(&circle);
    shapes.push_back(&square);

    // ͨ��ָ�����draw��resize����
    for (auto shape : shapes) {
        shape->draw();
        shape->resize(2);
    }

    return 0;
}