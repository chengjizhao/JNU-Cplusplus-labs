#include <iostream>
using namespace std;

// Drawable抽象基类
class Drawable {
public:
    virtual void draw() = 0;  // 纯虚函数
    virtual ~Drawable() {}  // 虚析构函数
};

// Resizable接口
class Resizable {
public:
    virtual void resize(int factor) = 0;  // 纯虚函数
    virtual ~Resizable() {}  // 虚析构函数
};

// Circle类从Drawable类派生，同时继承Resizable接口
class Circle : public Drawable, public Resizable {
public:
    void draw() override {
        cout << "Drawing a circle" << endl;
    }

    void resize(int factor) override {
        cout << "Resizing circle by " << factor << "%" << endl;
    }
};

// Square类从Drawable类派生，同时继承Resizable接口
class Square : public Drawable, public Resizable {
public:
    void draw() override {
        cout << "Drawing a square" << endl;
    }

    void resize(int factor) override {
        cout << "Resizing square by " << factor << "%" << endl;
    }
};

int main() {
    Drawable* shapes[2];  // 创建一个Drawable指针数组
    shapes[0] = new Circle();  // 包含一个Circle对象
    shapes[1] = new Square();  // 包含一个Square对象

    for (int i = 0; i < 2; i++) {
        shapes[i]->draw();  // 通过指针调用draw函数
        Resizable* resizableShape = dynamic_cast<Resizable*>(shapes[i]);
        if (resizableShape) {
            resizableShape->resize(50);  // 通过Resizable接口调用resize函数
        }
    }

    // 释放内存
    for (int i = 0; i < 2; i++) {
        delete shapes[i];
    }

    return 0;
}
