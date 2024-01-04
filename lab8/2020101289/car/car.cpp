/*创建一个汽车类的层次结构，包括一个基类 Car 和至少两个派生类
（例如，Sedan 和 SUV）。在基类中定义虚函数 calculatePrice，
而派生类应该覆盖此函数以计算各自类型的汽车价格。并画UML类图。
*/

#include"car.h"

Sedan::Sedan()
{
    price=2;
}
int Sedan::calculatePrice()
{
    return price;
}

SUV::SUV()
{
    price=3;
}
int SUV::calculatePrice()
{
    return price;
}