#include <iostream>
using namespace std;

class Shape
{
    public:
        virtual void draw() = 0; // 纯虚函数
};

class Circle : public Shape
{
    public:
        void draw()
        {
            cout << "Drawing a circle." << endl;
        }
};

int main()
{
    Circle circle;
    circle.draw();
    
    return 0;
}

// Shape类的虚函数表中只有一个指向draw()函数的地址。
// Circle类的虚函数表与Shape类相同，它继承了Shape的虚函数表。
// Circle对象在内存中分配了一个指向虚函数表的虚指针。
// 抽象类中的纯虚函数没有提供实现，所以无法直接实例化该类。但是，派生类必须实现所有纯虚函数才能实例化。