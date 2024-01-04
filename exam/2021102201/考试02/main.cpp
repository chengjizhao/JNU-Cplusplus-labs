//如果一个类包含虚函数，那么它的实例应该包含虚函数表指针等信息。UML图见附件。代码如下：

#include <iostream>

using namespace std;

class Shape
{
public:
    virtual void draw()
    {
        cout << "Drawing shape" << endl;
    }
};

class Circle : public Shape
{
public:
    void draw() override
    {
        cout << "Drawing circle" << endl;
    }
};

int main() {
    Shape* shape = new Circle();
    shape->draw();

    delete shape;

    return 0;
}

//我们创建了一个指向 Circle 对象的 Shape 指针。
//当调用 draw() 函数时，虚指针会被用来找到正确的虚函数表，并调用 Circle 类中的 draw() 函数。