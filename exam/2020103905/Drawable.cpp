#include <iostream>
#include <vector>

// 定义可绘制抽象基类
class Drawable {
public:
    virtual void draw() const = 0; // 纯虚函数
    virtual void resize(int factor) = 0; // 纯虚函数
};

// 定义可调整大小接口
class Resizable {
public:
    virtual void resize(int factor) = 0; // 纯虚函数
};

// 继承可绘制抽象基类的圆类
class Circle : public Drawable, public Resizable {
public:
    void draw() const override {
        // 绘制圆形
        std::cout << "Draw a circle" << std::endl;
    }

    void resize(int factor) override {
        // 调整圆形大小
        std::cout << "Resize the circle by factor " << factor << std::endl;
    }
};

// 继承可绘制抽象基类的正方形类
class Square : public Drawable, public Resizable {
public:
    void draw() const override {
        // 绘制正方形
        std::cout << "Draw a square" << std::endl;
    }

    void resize(int factor) override {
        // 调整正方形大小
        std::cout << "Resize the square by factor " << factor << std::endl;
    }
};

int main() {
    // 创建Drawable指针数组
    std::vector<Drawable*> shapes;
    Circle circle;
    Square square;
    shapes.push_back(&circle);
    shapes.push_back(&square);

    // 通过指针调用draw和resize函数
    for (auto shape : shapes) {
        shape->draw();
        shape->resize(2);
    }

    return 0;
}