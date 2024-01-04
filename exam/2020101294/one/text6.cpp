#include <iostream>

// 接口 Resizable
class Resizable {
public:
    virtual void resize(int factor) = 0;  // 纯虚函数
};

// 抽象基类 Drawable
class Drawable {
public:
    virtual void draw() const = 0;  // 纯虚函数
};

// 子类 Circle，继承 Drawable 和 Resizable 接口
class Circle : public Drawable, public Resizable {
public:
    void draw() const override {
        std::cout << "Drawing a circle." << std::endl;
    }

    void resize(int factor) override {
        std::cout << "Resizing the circle by a factor of " << factor << "." << std::endl;
    }
};

// 子类 Square，继承 Drawable 和 Resizable 接口
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
    // 创建 Drawable 指针数组，包含一个 Circle 和一个 Square 对象
    Drawable* shapes[2];
    Circle circle;
    Square square;
    shapes[0] = &circle;
    shapes[1] = &square;

    // 通过指针调用 draw 函数
    for (int i = 0; i < 2; ++i) {
        shapes[i]->draw();
    }

    // 通过指针调用 resize 函数
    for (int i = 0; i < 2; ++i) {
        Resizable* resizableShape = dynamic_cast<Resizable*>(shapes[i]);  // 尝试转换为 Resizable
        if (resizableShape) {
            resizableShape->resize(2);
        }
    }
    // 等待用户输入，防止程序立即退出
    std::cout << "Press Enter to exit." << std::endl;
    std::cin.get();
    return 0;
}