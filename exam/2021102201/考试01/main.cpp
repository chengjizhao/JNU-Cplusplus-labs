//如果一个类包含虚函数，那么它的实例将包含虚函数表指针等额外信息。UNL图见附件，代码如下：

#include <iostream>

using namespace std;

class Shape
{
public:
    virtual void draw() { std::cout << "Drawing shape" << std::endl; }
};

class Circle : public Shape
{
public:
    void draw() override { std::cout << "Drawing circle" << std::endl; }
};

int main()
{
    Shape* shape = new Circle();
    shape->draw();

    //delete shape;

    return 0;
}

//我们创建了一个指向 Circle 对象的 Shape 指针。
//当调用 draw() 函数时，虚指针会被用来找到正确的虚函数表，然后调用 Circle 类中的 draw() 函数。