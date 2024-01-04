/*
3.什么是纯虚函数和抽象类？它们如何与虚函数表和虚指针相关联？
通过一个包含纯虚函数的抽象类示例，说明它的虚函数表和虚指针的情况。
为什么包含纯虚函数的类不能实例化？请提供解释。
*/

#include <iostream>

using namespace std;

class Shape//基类
    {
        public:
            virtual double getArea() = 0;
    };

/*
   表示一个圆形的形状。
 */
class Circle : public Shape//继承类
    {
        private:
            double radius;

        public:
            //使用给定的半径构造一个 Circle 对象，r为圆的半径。
              
            Circle(double r)
            {
                radius = r;
            }
            // 计算圆的面积。
            double getArea()
            {
                return 3.14 * radius * radius;
            }
    };

int main()
{
    // Shape s; // 抽象类不能实例化
    Circle c(2);
    cout << c.getArea() << endl;
    return 0;
}



